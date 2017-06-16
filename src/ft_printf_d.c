/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:40:08 by niragne           #+#    #+#             */
/*   Updated: 2017/06/16 19:19:31 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_d(t_flags *flags, va_list ap)
{
	t_llint	nb;
	int			len;
	int			oui;
	char		*str;
	static void	(**f)(t_llint *, va_list) = NULL;

	if (f == NULL)
		fill_arr_signed(&f);
	f[TYPE](&nb, ap);
	len = nbrtostrneg(nb, &str, 10, FLAGS) - (!nb && !PREC && (FLAGS & FPREC));
	oui = *str == '-' || *str == '+' || *str == ' ';
	PREC = (!(PREC < len) * PREC - len) + oui;
	BLANKS -= PREC * (PREC > 0) + len;
	if (BLANKS > 0 && !(FLAGS & FSUB) && !(FLAGS & FZE))
		printchar(' ' + 16 * ((FLAGS & FZE) > 0), BLANKS);
	if (oui)
		ft_buf(1, str, 1);
	if (BLANKS > 0 && !(FLAGS & FSUB) && (FLAGS & FZE))
		printchar(' ' + 16 * ((FLAGS & FZE) > 0), BLANKS);
	if (PREC > 0)
		printchar('0', PREC);
	ft_buf(1, str + oui, len - oui);
	free(str);
	if (BLANKS > 0 && (FLAGS & FSUB))
		printchar(' ', BLANKS);
	return (len + BLANKS * (BLANKS > 0) + PREC * (PREC > 0));
}
