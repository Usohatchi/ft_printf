/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:41:11 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/16 09:50:40 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# define BUFF_SIZE 1024
# define CHECK_NULL(x, y) if (!x) return (y)
# define LOOKUP(x, y, z, i) while (x != y && z < i) z++
# define SET_CHAR(x, a, c) if (x) a = c
# define IS_WIDE(c) (c == 'S' || c == 'C')
# define IS_NWIDE(c) (c == 's' || c == 'c')
# define IS_STR(c) (IS_NWIDE(c) || IS_WIDE(c))
# define IS_DIGIT(c) (c >= '0' && c <= '9')
# define IS_FLAG(c) (c == '+' || c == '-' || c == '#' || c == ' ' || IS_MOD(c))
# define IS_WRITE(c) (IS_STR(c) || c == '%')
# define IS_INT(c) (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U')
# define IS_BASE(c) (c == 'p' || c == 'o' || c == 'O' || c == 'x' || c == 'X')
# define IS_FLOAT(c) (c == 'f')
# define IS_MOD(c) (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L')
# define IS_SPEC(c) (IS_WRITE(c) || IS_INT(c) || IS_BASE(c) || IS_FLOAT(c))

typedef struct	s_flag
{
	char		f;
	int			set;
}				t_flag;

typedef struct	s_len
{
	int			w;
	int			p;
	int			ps;
}				t_len;

typedef struct	s_func
{
	const char	f;
	char		*(*fmake)();
	int			base;
	const char	*p;
	const char	*key;
}				t_func;

int				ft_printf(const char *format, ...);
char			*ft_pfmdbl(va_list args);
char			*ft_pfmnbr(va_list args);
char			*ft_pfmnbru(va_list args);
char			*ft_pfmstr(va_list args);
char			*ft_pfmchar(va_list args);
char			*ft_pfmstrw(va_list args);
char			*ft_pfmcharw(va_list args);

#endif
