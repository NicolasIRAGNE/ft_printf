/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:41:20 by niragne           #+#    #+#             */
/*   Updated: 2017/06/17 13:59:53 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_c(t_flags *flags, va_list ap)
{
	unsigned char c;
	int i;
	char buf[BLANKS];
	
	if (flags->type == FL)
		return(ft_printf_lc2(flags, ap));
	c = va_arg(ap, int);
	if (c < 0)
		return (-1);
	BLANKS--;
	i = 0;
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
	return (BLANKS * (BLANKS > 0) + 1);
}