/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:40:08 by niragne           #+#    #+#             */
/*   Updated: 2017/06/13 17:08:51 by niragne          ###   ########.fr       */
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
	len = nbrtostrneg(nb, &str, 10) + ((FLAGS & FHT) > 0);
	PREC = (!(PREC < len) * PREC - len);
	BLANKS = (!(BLANKS < PREC + len) * BLANKS - (PREC + len) - len);
	if (BLANKS > 0 && !(FLAGS & FSUB))
		printchar(' ' + 16 * ((FLAGS & FZE) > 0), BLANKS);
	if (FLAGS & FHT)
		ft_buf(1, "0", 1);
	if (PREC > 0)
		printchar('0', PREC);
	ft_buf(1, str, len - ((FLAGS & FHT) > 0));
	if (BLANKS > 0 && (FLAGS & FSUB))
		printchar(' ', BLANKS);
	return (len + BLANKS * (BLANKS > 0) + PREC * (PREC > 0));
}
