/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:02:50 by niragne           #+#    #+#             */
/*   Updated: 2017/06/13 16:55:55 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cast_ulong(t_ullint *nb, va_list ap)
{
	*nb = va_arg(ap, t_ulint);
}

void	ft_cast_ulong_long(t_ullint *nb, va_list ap)
{
	*nb = va_arg(ap, t_ullint);
}
