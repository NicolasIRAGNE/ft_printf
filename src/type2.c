/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 17:53:16 by niragne           #+#    #+#             */
/*   Updated: 2017/06/19 17:05:25 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_ht(t_flags *flags, char **str)
{
	(void)str;
	FLAGS |= FHT;
}


void		add_dollar(t_flags *flags, char **str)
{
	(void)str;
	FLAGS |= FDOL;
}

void		add_zero(t_flags *flags, char **str)
{
	(void)str;
	if (!(FLAGS & PREC))
		FLAGS |= FZE;
}

void	add_minus(t_flags *flags, char **str)
{
	(void)str;
	FLAGS |= FSUB;
}

void		add_plus(t_flags *flags, char **str)
{
	(void)str;
	if (FLAGS & FSPACE)
		FLAGS ^= FSPACE;
	FLAGS |= FADD;
}
