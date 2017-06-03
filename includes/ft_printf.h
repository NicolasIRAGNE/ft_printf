/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 23:26:29 by anonymous         #+#    #+#             */
/*   Updated: 2017/06/03 16:56:17 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H	

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

# define FHT 0x1
# define FZE 0x2
# define FSUB 0x4
# define FADD 0x8
# define FSPACE 0x10
# define FMUL 0x20
# define FDOL 0x40
# define FL2 0x80
# define FAQ 0x100
# define FMAJ 0x200
# define FPREC 0x400
# define FHH 1
# define FH 2
# define FJ 3
# define FZ 4
# define FL 5
# define FLL 6

int		ft_printf(const char *format, ...);

typedef struct s_flags t_flags;
typedef unsigned int t_uint;

struct s_flags
{
	t_uint	flags;
	int		blanks;
	int		precision;
	int		type;
};

#endif