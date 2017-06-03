/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 23:44:07 by anonymous         #+#    #+#             */
/*   Updated: 2017/06/03 16:57:19 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf_error(va_list ap)
{
	ft_putstr("error ma couille\n");
	exit(1);
}

void	fill_error_func(int (*f[127])(va_list))
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
}

int		ft_printf_s(va_list ap)
{
	ft_putstr(va_arg(ap, char*));
	return (1);
}

int		ft_printf_d(va_list ap)
{
	ft_putnbr(va_arg(ap, int));
	return (1);
}

int		ft_printf_c(va_list ap)
{
	ft_putchar(va_arg(ap, int));
	return (1);
}

int		checkflags(const char *str, int i, va_list ap, int (*f[127])(va_list))
{
	f[str[i + 1]](ap);
	return (1);
}

void	fill_ptr_arr(int (*f[127])(va_list))
{
	fill_error_func(f);
	f['s'] = ft_printf_s;
	f['d'] = ft_printf_d;
	f['c'] = ft_printf_c;
}

int		ft_printf(const char *format, ...)
{
	int i;
	va_list ap;
	static int (*f[127])(va_list);
	unsigned int flags[127];

	va_start(ap, format);
	fill_flag_array(flags);
	fill_ptr_arr(f);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += checkflags(format, i, ap, f);
		}
		else
		{
			ft_putchar(format[i]);
		}
		i++;
	}
	return (i);
}