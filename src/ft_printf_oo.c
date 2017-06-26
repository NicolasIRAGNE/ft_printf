/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_oo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:42:39 by niragne           #+#    #+#             */
/*   Updated: 2017/06/25 15:58:41 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_oo(t_flags *flags, va_list ap)
{
	ft_type_l(flags, NULL);
	return (ft_printf_o(flags, ap));
}
