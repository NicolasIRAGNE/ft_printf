/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:21:08 by niragne           #+#    #+#             */
/*   Updated: 2017/06/16 21:44:23 by niragne          ###   ########.fr       */
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

	str = va_arg(ap, wchar_t*);
	if (!(len = ft_wstrlen(str)))
	{
		if (!str)
		{
			str = ft_wstrdup("(null)");
			FLAGS |= FNUL;
			len = 6;
		}
	}
	if (ft_check_wchar(str) == -1)
		return (-1);
	if (PREC > len || !(FLAGS & FPREC))
		PREC = len;
	BLANKS -= PREC;
	i = 0;
	if (BLANKS > 0 && !(FLAGS & FSUB))
	{
		ft_memset(buf, ' ' + 16 * ((FLAGS & FZE) > 0), BLANKS);
		ft_buf(1, buf, BLANKS);
	}
	ft_putwstr(str);
	if (BLANKS > 0 && (FLAGS & FSUB))
	{
		ft_memset(buf, ' ', BLANKS);
		ft_buf(1, buf, BLANKS);
	}
	if (FLAGS & FNUL)
		free(str);
	return (PREC + BLANKS * (BLANKS > 0) + 6 * (!(str)));
}
