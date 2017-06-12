/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 17:06:43 by niragne           #+#    #+#             */
/*   Updated: 2017/06/12 17:59:51 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_x(t_flags *flags, va_list ap)
{
	t_ullint	nb;
	int			len;
	char		*str;
	static void	(**f)(t_ullint *, va_list) = NULL;

	if (f == NULL)
		fill_arr(&f);
	f[TYPE](&nb, ap);
	len = nbrtostr(nb, &str, 16);
	if (BLANKS > 0 && (FLAGS & FHT))
		BLANKS -= 2;
	PREC = (!(PREC < len) * PREC - len);
	BLANKS = (!(BLANKS < PREC + len) * BLANKS - ((PREC > 0) * PREC + len));
	if (FLAGS & FZE && BLANKS > 0)
	{
		PREC = BLANKS;
		BLANKS = 0;
	}
	printf("%d %d\n", BLANKS, PREC);
	if (BLANKS > 0 && !(FLAGS & FSUB))
		printchar(' ' + 16 * ((FLAGS & FZE) && (!(FLAGS & FPREC))), BLANKS);
	if (FLAGS & FHT)
		write(1, "0x", 2);
	if (PREC > 0)
		printchar('0', PREC);
	write(1, str, len);
	if (BLANKS > 0 && (FLAGS & FSUB))
		printchar(' ', BLANKS);
	return (len + BLANKS + PREC);
}
