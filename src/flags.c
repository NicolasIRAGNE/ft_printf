/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 17:59:44 by niragne           #+#    #+#             */
/*   Updated: 2017/06/19 17:05:35 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_flag_ptr_arr(void (*f[256])(t_flags *, char **))
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

void	fill_func_ptr_arr(int (*f[256])(t_flags *, va_list))
{
	fill_error_func(f);
	f['s'] = ft_printf_s;
	f['S'] = ft_printf_ss;
	f['d'] = ft_printf_d;
	f['D'] = ft_printf_dd;
	f['c'] = ft_printf_c;
	f['C'] = ft_printf_lc;
	f['u'] = ft_printf_u;
	f['U'] = ft_printf_uu;
	f['o'] = ft_printf_o;
	f['O'] = ft_printf_oo;
	f['x'] = ft_printf_x;
	f['X'] = ft_printf_xx;
	f['p'] = ft_printf_p;
	f['%'] = ft_printf_pct;
	f['i'] = ft_printf_d;
	f['b'] = ft_printf_b;
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