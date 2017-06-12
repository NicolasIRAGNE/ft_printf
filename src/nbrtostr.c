/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrtostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 17:44:03 by niragne           #+#    #+#             */
/*   Updated: 2017/06/12 17:12:21 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char ft_getchar(int c)
{
	if (c < 10)
		return (c + '0');
	return (c + 'a' - 10);
}

int	nbrtostr(t_ullint nb, char **str, int base)
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
		(*str)[i] = ft_getchar(nb / div);
		nb %= div;
		div /= base;
		i++;
	}
	(*str)[i] = '\0';
	return (len);
}