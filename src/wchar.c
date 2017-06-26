/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 18:38:44 by niragne           #+#    #+#             */
/*   Updated: 2017/06/25 18:44:56 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putwcharbuf(wchar_t c)
{
	int				nb_bytes;
	unsigned int	ret;

	nb_bytes = 1;
	ret = 0;
	if (!(c >> (7 + (MB_CUR_MAX == 1))))
		ret = c;
	else if (!(c >> 11))
	{
		ret |= ((c & 0x3F) << 8) | ((c & 0x7C0) >> 6) | 0x80C0;
		nb_bytes = 2;
	}
	else if (!(c >> 16))
	{
		ret |= (c & 0x3F) << 16 | ((c & 0xFC0) << 2) | ((c & 0x1F000) >> 12);
		ret |= 0x8080E0;
		nb_bytes = 3;
	}
	else if (!(c >> 21))
	{
		ret = (((((c & 0x3f) << 24) | (((c >> 6) & 0x3f) << 16))
				| (((c >> 12) & 0x3f) << 8)) | (c >> 18)) | 0x808080f0;
		nb_bytes = 4;
	}
	return (ft_buf(1, &ret, nb_bytes));
}

int			ft_wcharlen(wchar_t c)
{
	int nb_bytes;

	nb_bytes = 1;
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

int			ft_wstrlen(wchar_t *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		j += ft_wcharlen(str[i]);
		i++;
	}
	return (j);
}

int			ft_putwstr(wchar_t *str)
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

wchar_t		*ft_wstrdup(char *str)
{
	wchar_t		*new;
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(str);
	if (!(new = (wchar_t *)malloc(sizeof(*new) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
