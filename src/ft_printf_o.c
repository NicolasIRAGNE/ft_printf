/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:57:52 by niragne           #+#    #+#             */
/*   Updated: 2017/06/12 16:53:19 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_o(t_flags *flags, va_list ap)
{
	t_ullint	nb;
	int			len;
	char		*str;
	static void	(**f)(t_ullint *, va_list) = NULL;

	if (f == NULL)
		fill_arr(&f);
	f[TYPE](&nb, ap);
	len = nbrtostr(nb, &str, 8) + ((FLAGS & FHT) > 0);
	PREC = (!(PREC < len) * PREC - len);
	BLANKS = (!(BLANKS < PREC + len) * BLANKS - (PREC + len));
	if (BLANKS > 0 && !(FLAGS & FSUB))
		printchar(' ' + 16 * ((FLAGS & FZE) > 0), BLANKS);
	if (FLAGS & FHT)
		write(1, "0", 1);
	if (PREC > 0)
		printchar('0', PREC);
	write(1, str, len);
	if (BLANKS > 0 && (FLAGS & FSUB))
		printchar(' ', BLANKS);
	return (len + BLANKS + PREC);
}
