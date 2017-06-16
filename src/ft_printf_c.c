/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:41:20 by niragne           #+#    #+#             */
/*   Updated: 2017/06/16 21:52:37 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_c(t_flags *flags, va_list ap)
{
	unsigned char c;
	int i;
	char buf[BLANKS];
	
	if (flags->type == FL && MB_CUR_MAX > 1)
		return(ft_printf_lc2(flags, ap));
	/*if (flags->type == FL && MB_CUR_MAX)
		return (-1);*/
	c = va_arg(ap, int);
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