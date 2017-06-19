/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 18:10:23 by niragne           #+#    #+#             */
/*   Updated: 2017/06/19 17:05:49 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_error(t_flags *flags, va_list ap)
{
	(void)flags;
	(void)ap;
	return (-2);
}

void	fill_error_func(int (*f[256])(t_flags *, va_list))
{
	int i;

	i = 0;
	while (i < 256)
	{
		f[i] = ft_printf_error;
		i++;
	}
}

void	fill_flag_array(unsigned int arr[256])
{
	int i;

	i = -1;
	while (++i < 256)
		arr[i] = 0;
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
	arr['z'] = 1;
	arr['l'] = 1;
	arr['h'] = 1;
	arr['j'] = 1;
}

int		checkflags(const char *str, va_list ap, int (*f[256])
	(t_flags *, va_list), t_flags *flags)
{
	return (f[(int)*str](flags, ap));
}