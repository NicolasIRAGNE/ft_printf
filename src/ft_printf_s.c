/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:39:03 by niragne           #+#    #+#             */
/*   Updated: 2017/06/13 15:30:42 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_s(t_flags *flags, va_list ap)
{
	char *str;
	int len;
	int i;
	char buf[BLANKS];

	str = va_arg(ap, char*);
	if (!(len = ft_strlen(str)))
		ft_buf(1, "(null)", 6);
	if (flags->type == FL)
		return(ft_printf_ls(flags, va_arg(ap, wchar_t *)));
	BLANKS -= len;
	if (PREC > len || !(FLAGS & FPREC))
		PREC = len;
	i = 0;
	if (BLANKS > 0 && !(FLAGS & FSUB))
	{
		ft_memset(buf, ' ' + 16 * ((FLAGS & FZE) > 0), BLANKS);
		ft_buf(1, buf, BLANKS);
	}
	ft_buf(1, str, PREC);
	if (BLANKS > 0 && (FLAGS & FSUB))
	{
		ft_memset(buf, ' ', BLANKS);
		ft_buf(1, buf, BLANKS);
	}
	return (PREC + BLANKS * (BLANKS > 0) + 6 * (!(len)));
}
