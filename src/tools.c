/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:58:29 by niragne           #+#    #+#             */
/*   Updated: 2017/06/25 18:41:05 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_arr(void (***f)(t_ullint *, va_list))
{
	if (!(*f = malloc(sizeof(**f) * 7)))
		exit(1);
	(*f)[0] = ft_cast_uint;
	(*f)[1] = ft_cast_uchar;
	(*f)[2] = ft_cast_ushort;
	(*f)[3] = ft_cast_uintmax;
	(*f)[4] = ft_cast_sizet;
	(*f)[5] = ft_cast_ulong;
	(*f)[6] = ft_cast_ulong_long;
}

void		fill_arr_signed(void (***f)(t_llint *, va_list))
{
	if (!(*f = malloc(sizeof(**f) * 7)))
		exit(1);
	(*f)[0] = ft_cast_int;
	(*f)[1] = ft_cast_char;
	(*f)[2] = ft_cast_short;
	(*f)[3] = ft_cast_intmax;
	(*f)[4] = ft_cast_ssizet;
	(*f)[5] = ft_cast_long;
	(*f)[6] = ft_cast_long_long;
}

void		printchar(int c, int size)
{
	char buf[size];

	ft_memset(buf, c, size);
	ft_buf(1, buf, size);
}

void		change_precision(t_flags *flags, char **str)
{
	flags->precision = 0;
	FLAGS |= FPREC;
	if (FLAGS & FZE)
		FLAGS ^= FZE;
	(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		flags->precision = flags->precision * 10 + **str - '0';
		(*str)++;
	}
}
