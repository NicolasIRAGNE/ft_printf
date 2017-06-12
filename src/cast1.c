/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:01:03 by niragne           #+#    #+#             */
/*   Updated: 2017/06/12 16:02:40 by niragne          ###   ########.fr       */
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
