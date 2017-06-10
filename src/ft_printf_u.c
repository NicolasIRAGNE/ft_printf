/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:40:47 by niragne           #+#    #+#             */
/*   Updated: 2017/06/10 18:04:51 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cast_int(t_ullint *nb, va_list ap)
{
	*nb = va_arg(ap, t_uint);
}

void	ft_cast_char(t_ullint *nb, va_list ap)
{
	*nb = va_arg(ap, t_uint);
	*nb = (unsigned char)*nb;
}

void	ft_cast_short(t_ullint *nb, va_list ap)
{
	*nb = va_arg(ap, t_uint);
	*nb = (unsigned short)*nb;
}

void	ft_cast_uintmax(t_ullint *nb, va_list ap)
{
	*nb = va_arg(ap, uintmax_t);
}

void	ft_cast_sizet(t_ullint *nb, va_list ap)
{
	*nb = va_arg(ap, size_t);
}

void	ft_cast_long(t_ullint *nb, va_list ap)
{
	*nb = va_arg(ap, t_ulint);
}

void	ft_cast_long_long(t_ullint *nb, va_list ap)
{
	*nb = va_arg(ap, t_ullint);
}

static void	fill_arr(void (***f)(t_ullint *, va_list))
{
	*f = malloc(sizeof(**f) * 7);
	(*f)[0] = ft_cast_int;
	(*f)[1] = ft_cast_char;
	(*f)[2] = ft_cast_short;
	(*f)[3] = ft_cast_uintmax;
	(*f)[4] = ft_cast_sizet;
	(*f)[5] = ft_cast_long;
	(*f)[6] = ft_cast_long_long;
}

int		ft_printf_u(t_flags *flags, va_list ap)
{
	t_ullint nb;
	int len;
	char 	*str;
	static void	(**f)(t_ullint *, va_list) = NULL;

	if (f == NULL)
		fill_arr(&f);
	f[TYPE](&nb, ap);
	len = nbrtostr(nb, &str, 10);
	write(1, str, len);
	return (len);
}
