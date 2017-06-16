/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:22:10 by niragne           #+#    #+#             */
/*   Updated: 2017/06/16 16:26:30 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <limits.h>

#define test "%S", L"abc mdr\x85445"



int	main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "");
	printf(" le mien %d \n", ft_printf(test));
	printf(" le vrai %d \n", printf(test));
	return 0;
	/*
	int i = 0;
	while (i < 150000)
	{
		if (i < 0xd800 || i > 0xdfff)
		{
			ft_printf("%C\n", i);
		}
		i++;
	}*/
}