/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:22:10 by niragne           #+#    #+#             */
/*   Updated: 2017/06/16 19:09:21 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <limits.h>

#define test "%03.1d", 1



int	main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "");
	printf(" le mien %d \n", ft_printf(test));
	printf(" le vrai %d \n", printf(test));
	return 0;
}