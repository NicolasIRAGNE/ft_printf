/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:22:10 by niragne           #+#    #+#             */
/*   Updated: 2017/06/19 17:05:17 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <limits.h>

#define test "hey, salut c'est %s, ca va %d %o %x %p %C", "jacky", 50,50,50,50,50



int	main(int argc, char const *argv[])
{
	int i = -500;

	setlocale(LC_ALL, "");
	printf(" le mien %d \n", ft_printf(test));
	printf(" le vrai %d \n", printf(test));

	return 0;
}