/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:21:08 by niragne           #+#    #+#             */
/*   Updated: 2017/06/16 16:26:14 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_wchar(wchar_t *str)
{
	int i;

	i = 0;
	if (MB_CUR_MAX != 4)
	{
		while (str[i])
		{
			if (ft_wcharlen(str[i]) > 1)
				return (-1);
			i++;
		}
	}
	return (i);
}

int		ft_printf_ss(t_flags *flags, va_list ap)
{
	wchar_t *str;
	int len;
	int i;
	char buf[BLANKS];
	int ret = 0;

	str = va_arg(ap, wchar_t*);
	if (!(len = ft_wstrlen(str)))
	{
		if (!str)
		{
			str = ft_wstrdup("(null)");
			len = 6;
		}
	}
	if (ft_check_wchar(str) == -1)
		return (-1);
	if (flags->type == FL)
		return(ft_printf_ls(flags, va_arg(ap, wchar_t *)));
	if (PREC > len || !(FLAGS & FPREC))
		PREC = len;
	BLANKS -= PREC;
	i = 0;
	if (BLANKS > 0 && !(FLAGS & FSUB))
	{
		ft_memset(buf, ' ' + 16 * ((FLAGS & FZE) > 0), BLANKS);
		ft_buf(1, buf, BLANKS);
	}
	ret += ft_putwstr(str);
	if (BLANKS > 0 && (FLAGS & FSUB))
	{
		ft_memset(buf, ' ', BLANKS);
		ft_buf(1, buf, BLANKS);
	}
	printf("%d %d\n", PREC, BLANKS);
	return (PREC + BLANKS * (BLANKS > 0) + 6 * (!(str)));
}
