/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:40:08 by niragne           #+#    #+#             */
/*   Updated: 2017/06/14 16:44:55 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_d(t_flags *flags, va_list ap)
{
	t_llint	nb;
	int			len;
	char		*str;
	static void	(**f)(t_llint *, va_list) = NULL;

	if (f == NULL)
		fill_arr_signed(&f);
	f[TYPE](&nb, ap);
	len = nbrtostrneg(nb, &str, 10, (FLAGS & FADD) > 0);
	PREC = (!(PREC < len) * PREC - len);
	BLANKS -= PREC * (PREC > 0) + len + ((FLAGS & (FADD | FSPACE)) > 0);
	if (BLANKS > 0 && !(FLAGS & FSUB))
		printchar(' ' + 16 * ((FLAGS & FZE) > 0), BLANKS);
	if (PREC > 0)
		printchar('0', PREC);
	ft_buf(1, str, len);
	free(str);
	if (BLANKS > 0 && (FLAGS & FSUB))
		printchar(' ', BLANKS);
	return (len + BLANKS * (BLANKS > 0) + PREC * (PREC > 0));
}
