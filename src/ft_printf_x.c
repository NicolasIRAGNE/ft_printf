/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 17:06:43 by niragne           #+#    #+#             */
/*   Updated: 2017/06/16 18:45:46 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_prefix(t_flags *flags)
{
	ft_buf(1, "0", 1);
	if (FLAGS & FMAJ)
		ft_buf(1, "X", 1);
	else
		ft_buf(1, "x", 1);
}

int		ft_printf_x(t_flags *flags, va_list ap)
{
	t_ullint	nb;
	int			len;
	char		*str;
	static void	(**f)(t_ullint *, va_list) = NULL;

	if (f == NULL)
		fill_arr(&f);
	f[TYPE](&nb, ap);
	len = nbrtostr(nb, &str, 16, ((FLAGS & FMAJ) > 0));
	if (BLANKS > 0 && (FLAGS & FHT))
		BLANKS -= 2;
	PREC = (!(PREC < len) * PREC - len);
	BLANKS = (!(BLANKS < PREC + len) * BLANKS - ((PREC > 0) * PREC + len));
	if (FLAGS & FHT && nb && (FLAGS & FZE))
		add_prefix(flags);
	if (BLANKS > 0 && !(FLAGS & FSUB))
		printchar(' ' + 16 * ((FLAGS & FZE) && (!(FLAGS & FPREC))), BLANKS);
	if (FLAGS & FHT && nb && !(FLAGS & FZE))
		add_prefix(flags);
	if (PREC > 0)
		printchar('0', PREC);
	ft_buf(1, str, len);
	if (BLANKS > 0 && (FLAGS & FSUB))
		printchar(' ', BLANKS);
	return (len + BLANKS * (BLANKS > 0) + PREC * (PREC > 0) + 2 * (((FLAGS & FHT) && nb) > 0));
}
