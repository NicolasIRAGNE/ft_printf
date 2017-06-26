/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:41:20 by niragne           #+#    #+#             */
/*   Updated: 2017/06/26 16:59:44 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_c(t_flags *flags, va_list ap)
{
	unsigned char	c;
	char			buf[BLANKS];

	if (flags->type == FL)
		return (ft_printf_lc2(flags, ap));
	c = va_arg(ap, int);
	if (c < 0)
		return (-1);
	BLANKS--;
	if (BLANKS > 0 && !(FLAGS & FSUB))
	{
		ft_memset(buf, ' ' + 16 * ((FLAGS & FZE) > 0), BLANKS);
		ft_buf(1, buf, BLANKS);
	}
	if (c > 127 && MB_CUR_MAX > 1)
		ft_buf(1, &c, 1);
	else
		ft_putwcharbuf(c);
	if (BLANKS > 0 && (FLAGS & FSUB))
	{
		ft_memset(buf, ' ', BLANKS);
		ft_buf(1, buf, BLANKS);
	}
	return (BLANKS * (BLANKS > 0) + 1);
}
