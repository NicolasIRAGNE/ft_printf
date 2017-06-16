/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 21:13:04 by niragne           #+#    #+#             */
/*   Updated: 2017/06/16 21:19:58 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_prefix(t_flags *flags)
{
	ft_buf(1, "0", 1);
	if (FLAGS & FMAJ)
		ft_buf(1, "B", 1);
	else
		ft_buf(1, "b", 1);
}


int		ft_printf_b(t_flags *flags, va_list ap)
{
	t_ullint	nb;
	int			len;
	char		*str;
	static void	(**f)(t_ullint *, va_list) = NULL;

	if (f == NULL)
		fill_arr(&f);
	f[TYPE](&nb, ap);
	len = nbrtostr(nb, &str, 2, ((FLAGS & FMAJ) > 0)) - (!nb && !PREC && (FLAGS & FPREC));
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
