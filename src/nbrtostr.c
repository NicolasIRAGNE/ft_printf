/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrtostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 17:44:03 by niragne           #+#    #+#             */
/*   Updated: 2017/06/10 18:04:40 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		(*str)[i] = nb / div + '0';
		nb %= div;
		div /= base;
		i++;
	}
	(*str)[i] = '\0';
	return (len);
}