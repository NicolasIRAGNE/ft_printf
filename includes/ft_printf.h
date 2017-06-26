/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 17:17:14 by niragne           #+#    #+#             */
/*   Updated: 2017/06/26 17:20:13 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# include <wchar.h>

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
# define FNUL 0x800
# define FHH 1
# define FH 2
# define FJ 3
# define FZ 4
# define FL 5
# define FLL 6
# define FLAGS flags->flags
# define BLANKS flags->blanks
# define PREC flags->precision
# define TYPE flags->type
# define RET beep.ret
# define TMP beep.tmp

int		ft_printf(const char *format, ...);

typedef struct s_flags			t_flags;
typedef struct s_itoa			t_itoa;
typedef unsigned int			t_uint;
typedef unsigned long long int	t_ullint;
typedef long long int			t_llint;
typedef unsigned long int		t_ulint;
typedef unsigned char			t_uchar;

struct	s_flags
{
	t_uint	flags;
	int		blanks;
	int		precision;
	int		type;
	int		ret;
	int		tmp;
};

struct	s_itoa
{
	int		i;
	t_llint	div;
	int		len;
	int		neg;
};

void	ft_type_l(t_flags *flags, char **str);
int		ft_printf_d(t_flags *flags, va_list ap);
int		ft_printf_s(t_flags *flags, va_list ap);
int		ft_printf_u(t_flags *flags, va_list ap);
int		ft_printf_uu(t_flags *flags, va_list ap);
int		ft_printf_lc(t_flags *flags, va_list ap);
int		ft_printf_c(t_flags *flags, va_list ap);
int		ft_printf_ls(t_flags *flags, wchar_t *str);
int		ft_printf_o(t_flags *flags, va_list ap);
int		ft_printf_x(t_flags *flags, va_list ap);
int		ft_printf_xx(t_flags *flags, va_list ap);
int		ft_printf_p(t_flags *flags, va_list ap);
int		ft_printf_dd(t_flags *flags, va_list ap);
int		ft_printf_ss(t_flags *flags, va_list ap);
int		ft_printf_oo(t_flags *flags, va_list ap);
int		ft_printf_b(t_flags *flags, va_list ap);
int		nbrtostr(t_ullint nb, char **str, int base, int maj);
void	ft_cast_uint(t_ullint *nb, va_list ap);
void	ft_cast_uchar(t_ullint *nb, va_list ap);
void	ft_cast_ushort(t_ullint *nb, va_list ap);
void	ft_cast_uintmax(t_ullint *nb, va_list ap);
void	ft_cast_sizet(t_ullint *nb, va_list ap);
void	ft_cast_ulong(t_ullint *nb, va_list ap);
void	ft_cast_ulong_long(t_ullint *nb, va_list ap);
void	ft_cast_int(t_llint *nb, va_list ap);
void	ft_cast_char(t_llint *nb, va_list ap);
void	ft_cast_short(t_llint *nb, va_list ap);
void	ft_cast_intmax(t_llint *nb, va_list ap);
void	ft_cast_ssizet(t_llint *nb, va_list ap);
void	ft_cast_long(t_llint *nb, va_list ap);
void	ft_cast_long_long(t_llint *nb, va_list ap);
void	fill_arr(void (***f)(t_ullint *, va_list));
void	fill_arr_signed(void (***f)(t_llint *, va_list));
void	printchar(int c, int size);
int		cmp(int a, int b);
int		ft_buf(int fd, void *str, int size);
int		nbneg(t_llint nb, char **str, int base, t_uint flags);
int		ft_putwcharbuf(wchar_t c);
int		ft_putwstr(wchar_t *str);
int		ft_wstrlen(wchar_t *str);
wchar_t	*ft_wstrdup(char *str);
int		ft_wcharlen(wchar_t c);
int		ft_printf_pct(t_flags *flags, va_list ap);
int		ft_printf_lc2(t_flags *flags, va_list ap);
void	add_space(t_flags *flags, char **str);
void	ft_type_j(t_flags *flags, char **str);
void	ft_type_z(t_flags *flags, char **str);
void	ft_type_h(t_flags *flags, char **str);
void	ft_type_l(t_flags *flags, char **str);
void	add_ht(t_flags *flags, char **str);
void	add_dollar(t_flags *flags, char **str);
void	add_zero(t_flags *flags, char **str);
void	add_minus(t_flags *flags, char **str);
void	add_plus(t_flags *flags, char **str);
void	fill_func_ptr_arr(int (*f[256])(t_flags *, va_list));
void	fill_flag_ptr_arr(void (*f[256])(t_flags *, char **));
void	init_flags(t_flags *flags);
void	ft_blanks(t_flags *flags, char **str);
int		ft_printf_error(t_flags *flags, va_list ap);
void	fill_error_func(int (*f[256])(t_flags *, va_list));
void	fill_flag_array(unsigned int arr[256]);
int		checkflags(const char *str, va_list ap, int (*f[256])
	(t_flags *, va_list), t_flags *flags);
void	change_precision(t_flags *flags, char **str);
int		iscaps(t_flags *flags, int nb);
int		ft_putwcharbuf(wchar_t c);
int		ft_wcharlen(wchar_t c);
int		ft_wstrlen(wchar_t *str);
int		ft_putwstr(wchar_t *str);
wchar_t	*ft_wstrdup(char *str);
int		ft_printf_n(t_flags *flags, va_list ap);

#endif
