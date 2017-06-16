/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:40:47 by niragne           #+#    #+#             */
/*   Updated: 2017/06/16 21:42:19 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_u(t_flags *flags, va_list ap)
{
	t_ullint	nb;
	int			len;
	char		*str;
	static void	(**f)(t_ullint *, va_list) = NULL;

	if (f == NULL)
		fill_arr(&f);
	f[TYPE](&nb, ap);
	len = nbrtostr(nb, &str, 10, 0);
	PREC = (!(PREC < len) * PREC - len);
	BLANKS -= PREC * (PREC > 0) + len;
	if (BLANKS > 0 && !(FLAGS & FSUB))
		printchar(' ' + 16 * ((FLAGS & FZE) > 0), BLANKS);
	if (PREC > 0)
		printchar('0', PREC);
	ft_buf(1, str, len);
	if (BLANKS > 0 && (FLAGS & FSUB))
		printchar(' ', BLANKS);
	free(str);
	return (len + BLANKS * (BLANKS > 0) + PREC * (PREC > 0));
}
