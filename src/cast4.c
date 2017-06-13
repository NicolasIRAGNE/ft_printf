/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:57:17 by niragne           #+#    #+#             */
/*   Updated: 2017/06/13 16:59:14 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cast_long(t_llint *nb, va_list ap)
{
	*nb = va_arg(ap, long int);
}

void	ft_cast_long_long(t_llint *nb, va_list ap)
{
	*nb = va_arg(ap, long long int);
}
