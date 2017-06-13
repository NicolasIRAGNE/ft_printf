/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:56:05 by niragne           #+#    #+#             */
/*   Updated: 2017/06/13 17:06:36 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cast_int(t_llint *nb, va_list ap)
{
	*nb = va_arg(ap, int);
}

void	ft_cast_char(t_llint *nb, va_list ap)
{
	*nb = va_arg(ap, int);
	*nb = (char)*nb;
}

void	ft_cast_short(t_llint *nb, va_list ap)
{
	*nb = va_arg(ap, int);
	*nb = (short)*nb;
}

void	ft_cast_intmax(t_llint *nb, va_list ap)
{
	*nb = va_arg(ap, intmax_t);
}

void	ft_cast_ssizet(t_llint *nb, va_list ap)
{
	*nb = va_arg(ap, ssize_t);
}
