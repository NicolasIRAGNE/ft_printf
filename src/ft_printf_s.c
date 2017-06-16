/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:39:03 by niragne           #+#    #+#             */
/*   Updated: 2017/06/16 21:36:04 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_s(t_flags *flags, va_list ap)
{
	char *str;
	int len;
	int i;
	char buf[BLANKS];

	if (flags->type == FL)
		return(ft_printf_ss(flags, ap));
	str = va_arg(ap, char*);
	if (!(len = ft_strlen(str)))
	{
		if (!str)
		{
			str = ft_strdup("(null)");
			FLAGS |= FNUL;
			len = 6;
		}
	}
	if (PREC > len || !(FLAGS & FPREC))
		PREC = len;
	BLANKS -= PREC;
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
	if (FLAGS & FNUL)
		free(str);
	return (PREC + BLANKS * (BLANKS > 0) + 6 * (!(str)));
}
