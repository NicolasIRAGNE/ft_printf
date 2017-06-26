/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:07:51 by niragne           #+#    #+#             */
/*   Updated: 2017/06/26 16:48:18 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_lc(t_flags *flags, va_list ap)
{
	ft_type_l(flags, NULL);
	return (ft_printf_c(flags, ap));
}

int		ft_printf_lc2(t_flags *flags, va_list ap)
{
	wchar_t		c;
	int			i;
	char		buf[BLANKS];

	c = va_arg(ap, wchar_t);
	BLANKS--;
	i = 0;
	if ((c > 255 && MB_CUR_MAX == 1) || c < 0)
		return (-3);
	if (BLANKS > 0 && !(FLAGS & FSUB))
	{
		ft_memset(buf, ' ' + 16 * ((FLAGS & FZE) > 0), BLANKS);
		ft_buf(1, buf, BLANKS);
	}
	ft_putwcharbuf(c);
	if (BLANKS > 0 && (FLAGS & FSUB))
	{
		ft_memset(buf, ' ', BLANKS);
		ft_buf(1, buf, BLANKS);
	}
	return (BLANKS * (BLANKS > 0) + ft_wcharlen(c));
}
