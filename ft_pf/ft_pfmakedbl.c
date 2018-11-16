/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfmakedbl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:24:39 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/16 13:21:44 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

extern t_flag	g_fl[];
extern t_len	g_len;
static size_t		ft_pfldbl(long double dbl);

/*
 *	g_fl[5] = 'l'
 *	g_fl[9] = 'L'
 */

static long double	ft_pfgetdata(va_list args)
{
	if (g_fl[9].set)
		return (va_arg(args, long double));
	else
		return ((long double)va_arg(args, double));
}

/*
 * 	g_fl[0] = '0'
 *	g_fl[1] = ' '
 *	g_fl[3] = '+'
 * 	g_fl[4] = '-'
 */

static size_t		ft_pflnbrdbl(intmax_t n)
{
	int			l;
	int			prefix;

	l = (n || !g_len.ps || g_len.p > 0) ? (int)ft_getdigits(n, 10) : 0;
	prefix = ((n < 0 || g_fl[1].set || g_fl[3].set) ? 1 : 0);
	if (g_fl[0].set && !g_fl[4].set && !g_len.ps)
		g_len.w -= prefix;
	else if (g_len.ps && g_len.p < 0)
		g_len.p = 0;
	return ((l + prefix) * sizeof(char));
}

static char			*ft_pfmnbrdbl(intmax_t n, long double d)
{
	int			dl;
	int			l;
	int			i;
	char		*str;

	dl = ft_pflnbrdbl(n);
	l = (g_len.w > dl + (int)ft_pfldbl(d) && !g_fl[4].set) ? g_len.w - (int)ft_pfldbl(d): dl;
	str = ft_strnew(l);
	ft_memset(str, ((g_fl[0].set && !g_fl[4].set) ? '0' : ' '), l);
	SET_CHAR((g_fl[1].set), str[l - dl], ' ');
	SET_CHAR((g_fl[3].set), str[l - dl], '+');
	SET_CHAR((n < 0), str[l - dl], '-');
	i = (n || !g_len.ps || g_len.p > 0) ? (int)ft_getdigits(n, 10) : 0;
	while (i-- && (n || g_len.p))
	{
		str[--l] = n % 10 * ((n < 0) ? -1 : 1) + '0';
		n /= 10;
	}
	return (str);
}

static size_t		ft_pfldbl(long double dbl)
{
	int		l;
	int		dec;

	if (!g_len.ps)
		g_len.p = 6;
	l = (g_len.p > 0) ? g_len.p : 0;
	dec = (g_fl[2].set || g_len.p > 0) ? 1 : 0;
	if (g_fl[4].set && g_len.w > (int)ft_pflnbrdbl((intmax_t)dbl) + l + dec)
		return (g_len.w - (int)ft_pflnbrdbl((intmax_t)dbl));
	return (l + dec);
}

char				*ft_pfmdbl(va_list args)
{
	long double	dbl;
	char		*str;
	char		*ret;
	int			l;
	uintmax_t	c;
	
	dbl = ft_pfgetdata(args);
	ret = ft_pfmnbrdbl((intmax_t)dbl, dbl);
	l = ft_pfldbl(dbl);
	str = ft_strnew(l);
	ft_memset(str, ' ', l);
	c = ft_convert((dbl - (intmax_t)dbl) * ((dbl < 0) ? -1 : 1), g_len.p);
	if (g_fl[2].set || g_len.p > 0)
		str[0] = '.';
	l = (g_fl[4].set) ? ft_getdigitsuns(c, 10) + 1 : l;
	while (--l >= 1)
	{
		str[l] = c % 10 + '0';
		c /= 10;
	}
	ret = ft_strappend(ret, str, ft_strlen(ret), ft_strlen(str));
	free(str);
	return (ret);
}
