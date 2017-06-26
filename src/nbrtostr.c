/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrtostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 17:44:03 by niragne           #+#    #+#             */
/*   Updated: 2017/06/26 16:42:45 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_getchar(int c, int maj)
{
	if (c < 10)
		return (c + '0');
	return (c + 'a' - 10 - 32 * maj);
}

int			nbrtostr(t_ullint nb, char **str, int base, int maj)
{
	int			i;
	t_ullint	div;
	int			len;

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

void		init_itoa(t_itoa *data)
{
	data->len = 1;
	data->div = -1;
	data->i = 0;
	data->neg = 0;
}

void		loop(t_itoa *data, char **str, t_llint nb, int base)
{
	while (data->div < 0)
	{
		(*str)[data->i] = ft_getchar(nb / data->div, 0);
		nb %= data->div;
		data->div /= base;
		data->i++;
	}
}

int			nbneg(t_llint nb, char **str, int base, t_uint flags)
{
	t_itoa data;

	init_itoa(&data);
	data.neg += (nb < 0);
	nb -= (2 * nb) * (nb >= 0);
	if (((flags & (FADD | FSPACE)) > 0) || data.neg)
	{
		data.len = 2;
		data.i = 1;
	}
	while (data.div >= nb / base)
	{
		data.div *= base;
		data.len++;
	}
	if (!(*str = (char *)malloc(sizeof(**str) * (data.len + 1))))
		exit(1);
	if (data.neg || (flags & (FADD | FSPACE)))
		(*str)[0] = '-' - (2 * ((flags & FADD) > 0) + 13
		* ((flags & FSPACE) > 0)) * !data.neg;
	loop(&data, str, nb, base);
	(*str)[data.i] = '\0';
	return (data.len);
}
