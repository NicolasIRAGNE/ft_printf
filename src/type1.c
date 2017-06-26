/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 17:38:57 by niragne           #+#    #+#             */
/*   Updated: 2017/06/25 18:36:28 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_space(t_flags *flags, char **str)
{
	if (!(FLAGS & FADD))
		FLAGS |= FSPACE;
	if (str)
		(*str)++;
}

void	ft_type_j(t_flags *flags, char **str)
{
	if (TYPE < FJ)
		TYPE = FJ;
	if (str)
		(*str)++;
}

void	ft_type_z(t_flags *flags, char **str)
{
	if (TYPE < FZ)
		TYPE = FZ;
	if (str)
		(*str)++;
}

void	ft_type_h(t_flags *flags, char **str)
{
	if (TYPE < FH)
		TYPE = FH;
	else if (TYPE == FH)
		TYPE = FHH;
	if (str)
		(*str)++;
}

void	ft_type_l(t_flags *flags, char **str)
{
	if (TYPE < FL)
		TYPE = FL;
	else if (TYPE == FL)
		TYPE = FLL;
	if (str)
		(*str)++;
}
