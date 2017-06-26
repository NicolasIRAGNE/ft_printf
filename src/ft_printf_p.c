/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 17:15:52 by niragne           #+#    #+#             */
/*   Updated: 2017/06/25 16:37:10 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_p(t_flags *flags, va_list ap)
{
	t_ulint		nb;
	int			len;
	char		*str;
	static void	(**f)(t_ullint *, va_list) = NULL;

	if (f == NULL)
		fill_arr(&f);
	nb = va_arg(ap, t_ulint);
	len = nbrtostr(nb, &str, 16, 0);
	BLANKS -= 2 * (BLANKS > 0);
	PREC = (!(PREC < len) * PREC - len);
	BLANKS = (!(BLANKS < PREC + len) * BLANKS - ((PREC > 0) * PREC + len));
	PREC = (FLAGS & FZE && BLANKS > 0) ? BLANKS : PREC;
	BLANKS -= BLANKS * (FLAGS & FZE && BLANKS > 0);
	if (BLANKS > 0 && !(FLAGS & FSUB))
		printchar(' ' + 16 * ((FLAGS & FZE) && (!(FLAGS & FPREC))), BLANKS);
	ft_buf(1, "0x", 2);
	if (PREC > 0)
		printchar('0', PREC);
	ft_buf(1, str, len);
	if (BLANKS > 0 && (FLAGS & FSUB))
		printchar(' ', BLANKS);
	free(str);
	return (len + BLANKS * (BLANKS > 0) + PREC * (PREC > 0) + 2);
}
