/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 23:45:52 by anonymous         #+#    #+#             */
/*   Updated: 2017/06/03 17:13:31 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int	main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "");
	//ft_printf("salut c'est %s, %d %d %c %c %c\n", "jacky", 95 , 100, 'C', 'U', 'L');
	printf("\n", "salut");
	return 0;
}