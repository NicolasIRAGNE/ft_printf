/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:39:03 by niragne           #+#    #+#             */
/*   Updated: 2017/06/12 18:38:40 by niragne          ###   ########.fr       */
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
	len = ft_strlen(str);
	if (flags->type == FL)
		return(ft_printf_ls(flags, va_arg(ap, wchar_t *)));
	BLANKS -= len;
	if (PREC > len || !(FLAGS & FPREC))
		PREC = len;
	i = 0;
	if (BLANKS > 0 && !(FLAGS & FSUB))
	{
		ft_memset(buf, ' ' + 16 * ((FLAGS & FZE) > 0), BLANKS);
		write(1, buf, BLANKS);
	}
	write(1, str, PREC);
	if (BLANKS > 0 && (FLAGS & FSUB))
	{
		ft_memset(buf, ' ', BLANKS);
		write(1, buf, BLANKS);
	}
	return (PREC + BLANKS * (BLANKS > 0));
}
