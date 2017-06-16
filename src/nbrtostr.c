/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrtostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 17:44:03 by niragne           #+#    #+#             */
/*   Updated: 2017/06/16 18:37:12 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char ft_getchar(int c, int maj)
{
	if (c < 10)
		return (c + '0');
	return (c + 'a' - 10 - 32 * maj);
}

int	nbrtostr(t_ullint nb, char **str, int base, int maj)
{
	int i;
	t_ullint div;
	int len;

	len = 1;
	div = 1;
	while (div <= nb / base)
	{
		div *= base;
		len++;
	}
	if (!(*str = (char *)malloc(sizeof(**str) * (len + 1))))
		exit(1);
	i = 0;
	while (div > 0)
	{
		(*str)[i] = ft_getchar(nb / div, maj);
		nb %= div;
		div /= base;
		i++;
	}
	(*str)[i] = '\0';
	return (len);
}

int	nbrtostrneg(t_llint nb, char **str, int base, t_uint flags)
{
	int i;
	t_llint div;
	int len;
	int neg;

	len = 1;
	div = -1;
	i = 0;
	neg = 0;
	if (nb >= 0)
		nb = -nb;
	else
		neg = 1;
	if (((flags & (FADD | FSPACE)) > 0) || neg)
	{
		len = 2;
		i = 1;
	}
	while (div >= nb / base)
	{
		div *= base;
		len++;
	}
	if (!(*str = (char *)malloc(sizeof(**str) * (len + 1))))
		exit(1);
	if (neg || (flags & (FADD | FSPACE)))
	{
		(*str)[0] = '-' - (2 * ((flags & FADD) > 0) + 13 * ((flags & FSPACE) > 0)) * !neg;
	}
	while (div < 0)
	{
		(*str)[i] = ft_getchar(nb / div, 0);
		nb %= div;
		div /= base;
		i++;
	}
	(*str)[i] = '\0';
	return (len);
}