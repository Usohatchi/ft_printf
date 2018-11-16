/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfmakenbru.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:24:39 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/11 18:31:35 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"
#include <stdio.h>

extern int		g_i;
extern t_len	g_len;
extern t_flag	g_fl[];
extern t_func	g_func[];

/*
 * 	g_fl[4] = '-'
 *	g_fl[5] = 'l'
 *	g_fl[6] = 'h'
 *	g_fl[7] = 'j'
 *	g_fl[8] = 'z'
 */

static intmax_t		ft_pfgetdatauns(va_list args)
{
	unsigned short int	shorti;
	unsigned char		chari;

	if (g_func[g_i].f == 'p' || g_func[g_i].f == 'U' || g_func[g_i].f == 'O')
		return (va_arg(args, unsigned long));
	else if (g_fl[7].set)
		return (va_arg(args, uintmax_t));
	else if (g_fl[5].set >= 2)
		return (va_arg(args, unsigned long long));
	else if (g_fl[5].set == 1)
		return ((uintmax_t)va_arg(args, unsigned long));
	else if (g_fl[8].set)
		return ((uintmax_t)va_arg(args, size_t));
	else if (g_fl[6].set == 1)
	{
		shorti = va_arg(args, int);
		return ((uintmax_t)shorti);
	}
	else if (g_fl[6].set)
	{
		chari = va_arg(args, int);
		return ((uintmax_t)chari);
	}
	else
		return ((uintmax_t)va_arg(args, unsigned int));
}

/*
 * 	g_fl[0] = '0'
 * 	g_fl[2] = '#'
 * 	g_fl[4] = '-'
 */

static size_t		ft_pflnbru(uintmax_t n)
{
	int			l;
	int			prefix;
	int			prec;

	l = (n || g_len.p) ? (int)ft_getdigitsuns(n, g_func[g_i].base) : 0;
	prefix = ((g_fl[2].set && (n || (g_func[g_i].base == 8 && !g_len.p)))
			|| g_func[g_i].f == 'p') ? ft_strlen(g_func[g_i].p) : 0;
	if (g_fl[0].set && !g_fl[4].set && !g_len.ps)
	{
		g_len.p = g_len.w - prefix;
		g_len.w = -1;
	}
	else if (g_len.ps && g_len.p < 0)
		g_len.p = 0;
	prec = (g_len.p > l) ? g_len.p - l : 0;
	return ((l + prefix + prec) * sizeof(char));
}

/*
 *	 g_fl[0] = '0'
 *	 g_fl[2] = '#'
 *	 g_fl[4] = '-'
 */

char				*ft_pfmnbru(va_list args)
{
	uintmax_t	n;
	int			dl;
	int			l;
	int			i;
	char		*str;

	n = ft_pfgetdatauns(args);
	dl = ft_pflnbru(n);
	l = (g_len.w > dl) ? g_len.w : dl;
	str = ft_strnew(l);
	ft_memset(str, ' ', l);
	l = (g_fl[4].set) ? dl : l;
	if ((g_fl[2].set && (n || (g_func[g_i].base == 8 && !g_len.p)))
			|| g_func[g_i].f == 'p')
		ft_strncpy(str + (l - dl), g_func[g_i].p, ft_strlen(g_func[g_i].p));
	i = (n || g_len.p) ? (int)ft_getdigitsuns(n, g_func[g_i].base) : 0;
	while (i-- && (n || g_len.p))
	{
		str[--l] = g_func[g_i].key[n % g_func[g_i].base];
		n /= g_func[g_i].base;
		g_len.p--;
	}
	while (g_len.p-- > 0)
		str[--l] = '0';
	return (str);
}
