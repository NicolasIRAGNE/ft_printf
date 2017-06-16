/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:22:10 by niragne           #+#    #+#             */
/*   Updated: 2017/06/16 21:50:04 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <limits.h>

#define test "%C", 0xff



int	main(int argc, char const *argv[])
{
	int i = 54;

	printf(" le mien %d \n", ft_printf(test));
	printf(" le vrai %d \n", printf(test));
	return 0;
}