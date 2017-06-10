/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 23:44:07 by anonymous         #+#    #+#             */
/*   Updated: 2017/06/10 18:05:16 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf_error(t_flags *flags, va_list ap)
{
	ft_putstr("error ma couille\n");
	exit(1);
}

void	fill_error_func(int (*f[127])(t_flags *, va_list))
{
	int i;

	i = 0;
	while (i < 127)
	{
		f[i] = ft_printf_error;
		i++;
	}
}

void	fill_flag_array(unsigned int arr[127])
{
	int i;

	i = 0;
	while (i < 127)
	{
		arr[i] = 0;
		i++;
	}
	arr['#'] = 1;
	arr['0'] = 1;
	arr['1'] = 1;
	arr['2'] = 1;
	arr['3'] = 1;
	arr['4'] = 1;
	arr['5'] = 1;
	arr['6'] = 1;
	arr['7'] = 1;
	arr['8'] = 1;
	arr['9'] = 1;
	arr['.'] = 1;
	arr['-'] = 1;
	arr[' '] = 1;
	arr['+'] = 1;
	arr['$'] = 1;
	arr['*'] = 1;
	arr['z'] = 1;
	arr['l'] = 1;
	arr['h'] = 1;
	arr['j'] = 1;
}

int		ft_printf_ls(t_flags *flags, wchar_t *str)
{
	return (1);
}

int		checkflags(const char *str, va_list ap, int (*f[127])(t_flags *, va_list), t_flags *flags)
{
	f[*str](flags, ap);
	return (1);
}

void	fill_func_ptr_arr(int (*f[127])(t_flags *, va_list))
{
	fill_error_func(f);
	f['s'] = ft_printf_s;
	f['d'] = ft_printf_d;
	f['c'] = ft_printf_c;
	f['u'] = ft_printf_u;	
}

void		add_ht(t_flags *flags, char **str)
{
	FLAGS |= FHT;
}

void		add_dollar(t_flags *flags, char **str)
{
	FLAGS |= FDOL;
}

void		add_zero(t_flags *flags, char **str)
{
	FLAGS |= FZE;
}

void	add_minus(t_flags *flags, char **str)
{
	FLAGS |= FSUB;
}

void		add_plus(t_flags *flags, char **str)
{
	FLAGS |= FADD;
}

void		change_precision(t_flags *flags, char **str)
{
	flags->precision = 0;
	FLAGS |= FPREC;
	(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		flags->precision = flags->precision * 10 + **str - '0';
		(*str)++;
	}
	(*str)--;
}

void		ft_blanks(t_flags *flags, char **str)
{
	BLANKS = 0;
	while (**str >= '0' && **str <= '9')
	{
		BLANKS = BLANKS * 10 + **str - '0';
		(*str)++;
	}
	(*str)--;
}

void		add_space(t_flags *flags, char **str)
{
	FLAGS |= FSPACE;
}

void	ft_type_j(t_flags *flags, char **str)
{
	(void)str;
	if (TYPE < FJ)
		TYPE = FJ;
}

void	ft_type_z(t_flags *flags, char **str)
{
	(void)str;
	if (TYPE < FZ)
		TYPE = FZ;
}

void	ft_type_h(t_flags *flags, char **str)
{
	(void)str;
	if (TYPE < FH)
		TYPE = FH;
	else if (TYPE == FH)
		TYPE = FHH;
}

void	ft_type_l(t_flags *flags, char **str)
{
	(void)str;
	if (TYPE < FL)
		TYPE = FL;
	else if (TYPE == FL)
		TYPE = FLL;
}

void 	fill_flag_ptr_arr(void (*f[127])(t_flags *, char **))
{
	f['#'] = add_ht;
	f['$'] = add_dollar;
	f['0'] = add_zero;
	f['+'] = add_plus;
	f['-'] = add_minus;
	f['.'] = change_precision;
	f[' '] = add_space;
	f['1'] = ft_blanks;
	f['2'] = ft_blanks;
	f['3'] = ft_blanks;
	f['4'] = ft_blanks;
	f['5'] = ft_blanks;
	f['6'] = ft_blanks;
	f['7'] = ft_blanks;
	f['8'] = ft_blanks;
	f['9'] = ft_blanks;
	f['j'] = ft_type_j;
	f['z'] = ft_type_z;
	f['h'] = ft_type_h;
	f['l'] = ft_type_l;
}

void	init_flags(t_flags *flags)
{
	BLANKS = 0;
	TYPE = 0;
	PREC = 0;
	FLAGS = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_flags beep;
	static int (*f[127])(t_flags *, va_list);
	static void (*flagptr[127])(t_flags *, char **);
	static t_uint flags[127] = {-1};

	va_start(ap, format);
	if (flags[0] == -1)
	{
		fill_flag_array(flags);
		fill_func_ptr_arr(f);
		fill_flag_ptr_arr(flagptr);
	}
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			init_flags(&beep);
			while (flags[*format])
			{
				flagptr[*format](&beep, (char**)&format);
				format++;
			}
			checkflags(format, ap, f, &beep);
		}
		else
		{
			ft_putchar(*format);
		}
		format++;
	}
	return (0);
}