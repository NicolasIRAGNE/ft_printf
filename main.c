/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:22:10 by niragne           #+#    #+#             */
/*   Updated: 2017/06/12 18:39:03 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

#define test "salut ca va %o mdr lol\n", 244

int	main(int argc, char const *argv[])
{
	printf("le mien %d \n", ft_printf(test));
	printf("le vrai %d \n", printf(test));
	return 0;
}

