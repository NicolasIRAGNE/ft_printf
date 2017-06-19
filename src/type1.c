/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 17:38:57 by niragne           #+#    #+#             */
/*   Updated: 2017/06/19 17:05:46 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_space(t_flags *flags, char **str)
{
	(void)str;
	if (!(FLAGS & FADD))
		FLAGS |= FSPACE;
}

void	ft_type_j(t_flags *flags, char **str)
{
	(void)str;
	if (TYPE < FJ)
		TYPE = FJ;
}

void	ft_type_z(t_flags *flags, char **str)
{
	(void)str;
	if (TYPE < FZ)
		TYPE = FZ;
}

void	ft_type_h(t_flags *flags, char **str)
{
	(void)str;
	if (TYPE < FH)
		TYPE = FH;
	else if (TYPE == FH)
		TYPE = FHH;
}

void	ft_type_l(t_flags *flags, char **str)
{
	(void)str;
	if (TYPE < FL)
		TYPE = FL;
	else if (TYPE == FL)
		TYPE = FLL;
}