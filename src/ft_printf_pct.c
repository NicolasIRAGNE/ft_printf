/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:06:22 by niragne           #+#    #+#             */
/*   Updated: 2017/06/17 14:22:55 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_pct(t_flags *flags, va_list ap)
{
	int i;
	char buf[BLANKS];
	
	(void)ap;
	BLANKS--;
	i = 0;
	if (BLANKS > 0 && !(FLAGS & FSUB))
	{
		ft_memset(buf, ' ' + 16 * ((FLAGS & FZE) > 0), BLANKS);
		ft_buf(1, buf, BLANKS);
	}
	ft_buf(1, "%", 1);
	if (BLANKS > 0 && (FLAGS & FSUB))
	{
		ft_memset(buf, ' ', BLANKS);
		ft_buf(1, buf, BLANKS);
	}
	return (BLANKS * (BLANKS > 0) + 1);
}