/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 17:24:10 by niragne           #+#    #+#             */
/*   Updated: 2017/06/19 17:03:08 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	init_all(int (*f[256])(t_flags *, va_list),
 void (*flagptr[256])(t_flags *, char **), t_uint flags[256], t_flags *beep)
{
	beep->ret = 0;
	if (flags[0] == (t_uint)-1)
	{
		fill_flag_array(flags);
		fill_func_ptr_arr(f);
		fill_flag_ptr_arr(flagptr);
	}
}

void	end_buf(void)
{
	ft_buf(1, "", 1);
	ft_buf(1, NULL, -1);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_flags			beep;
	static int		(*f[256])(t_flags *, va_list);
	static void		(*flagptr[256])(t_flags *, char **);
	static t_uint	flags[256] = {-1};

	va_start(ap, format);
	init_all(f, flagptr, flags, &beep);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			init_flags(&beep);
			while (flags[(int)*format])
			{
				flagptr[(int)*format](&beep, (char**)&format);
			}
			TMP = checkflags(format, ap, f, &beep);
			format -= (TMP == -2);
			RET += TMP * (!(TMP == -2));
		}
		else
		{
			RET++;
			ft_buf(1, (void*)format, 1);
		}
		format++;
	}
	end_buf();
	return (RET);
}
