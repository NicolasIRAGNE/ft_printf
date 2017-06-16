/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:07:51 by niragne           #+#    #+#             */
/*   Updated: 2017/06/16 15:53:23 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putwcharbuf(wchar_t c)
{
	int nb_bytes = 1;
	int masque = 0xf0e0c080;
	unsigned int ret = 0;

	if (!(c >> (7 + (MB_CUR_MAX == 1))))
	{
		ret = c;
		nb_bytes = 1;
	}
	else if (!(c >> 11))
	{
		ret |= ((c & 0x3F) << 8);
		ret |= ((c & 0x7C0) >> 6);
		ret |= 0x80C0;
		nb_bytes = 2;
	}
	else if (!(c >> 16))
	{
		ret |= (c & 0x3F) << 16;
		ret |= (c & 0xFC0) << 2;
		ret |= (c & 0x1F000) >> 12;
		ret |= 0x8080E0;
		nb_bytes = 3;
	}
	else if (!(c >> 21))
	{
		ret = (((((c & 0x3f) << 24) | (((c >> 6) & 0x3f) << 16))
				| (((c >> 12) & 0x3f) << 8)) | (c >> 18)) | 0x808080f0;
		nb_bytes = 4;
	}
	ft_buf(1, &ret, nb_bytes);
	return (nb_bytes);
}

int	ft_wcharlen(wchar_t c)
{
	int nb_bytes;

	if (!(c >> (7 + (MB_CUR_MAX == 1))))
		nb_bytes = 1;
	else if (!(c >> 11))
		nb_bytes = 2;
	else if (!(c >> 16))
		nb_bytes = 3;
	else if (!(c >> 21))
		nb_bytes = 4;
	return (nb_bytes);
}

int	ft_wstrlen(wchar_t *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j += ft_wcharlen(str[i]);
		i++;
	}
	return (j);
}

int	ft_putwstr(wchar_t *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j += ft_putwcharbuf(str[i]);
		i++;
	}
	return (j);
}

wchar_t	*ft_wstrdup(char *str)
{
	wchar_t		*new;
	size_t		i;
	int 		len;

	i = 0;

	len = ft_strlen(str);
	if (!(new = (wchar_t *)malloc(sizeof(*new) * len + 1)))
		return (NULL);
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

int		ft_printf_lc(t_flags *flags, va_list ap)
{
	ft_type_l(flags, NULL);
	return (ft_printf_c(flags, ap));
}

int		ft_printf_lc2(t_flags *flags, va_list ap)
{
	wchar_t c;
	int i;
	char buf[BLANKS];
	
	c = va_arg(ap, wchar_t);
	BLANKS--;
	i = 0;
	if (BLANKS > 0 && !(FLAGS & FSUB))
	{
		ft_memset(buf, ' ' + 16 * ((FLAGS & FZE) > 0), BLANKS);
		ft_buf(1, buf, BLANKS);
	}
	ft_putwcharbuf(c);
	if (BLANKS > 0 && (FLAGS & FSUB))
	{
		ft_memset(buf, ' ', BLANKS);
		ft_buf(1, buf, BLANKS);
	}
	return (BLANKS * (BLANKS > 0) + ft_wcharlen(c));
}
