/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 17:53:16 by niragne           #+#    #+#             */
/*   Updated: 2017/06/25 18:37:22 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_ht(t_flags *flags, char **str)
{
	FLAGS |= FHT;
	if (str)
		(*str)++;
}

void		add_dollar(t_flags *flags, char **str)
{
	FLAGS |= FDOL;
	if (str)
		(*str)++;
}

void		add_zero(t_flags *flags, char **str)
{
	if (!(FLAGS & PREC))
		FLAGS |= FZE;
	if (str)
		(*str)++;
}

void		add_minus(t_flags *flags, char **str)
{
	FLAGS |= FSUB;
	if (str)
		(*str)++;
}

void		add_plus(t_flags *flags, char **str)
{
	if (FLAGS & FSPACE)
		FLAGS ^= FSPACE;
	FLAGS |= FADD;
	if (str)
		(*str)++;
}
