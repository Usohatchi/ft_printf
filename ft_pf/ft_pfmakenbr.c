/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfmakenbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:24:39 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/16 11:52:30 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"
#include <stdio.h>

extern t_flag	g_fl[];
extern t_len	g_len;

/*
 *	g_fl[5] = 'l'
 *	g_fl[6] = 'h'
 *	g_fl[7] = 'j'
 *	g_fl[8] = 'z'
 */

static intmax_t		ft_pfgetdata(va_list args)
{
	short int	shorti;
	signed char	chari;

	shorti = 0;
	chari = 0;
	if (g_fl[7].set)
		return (va_arg(args, intmax_t));
	else if (g_fl[5].set >= 2)
		return ((intmax_t)va_arg(args, long long));
	else if (g_fl[5].set == 1)
		return ((intmax_t)va_arg(args, long));
	else if (g_fl[8].set)
		return ((intmax_t)va_arg(args, ssize_t));
	else if (g_fl[6].set == 1)
	{
		shorti = va_arg(args, int);
		return ((intmax_t)shorti);
	}
	else if (g_fl[6].set)
	{
		chari = va_arg(args, int);
		return ((intmax_t)chari);
	}
	else
		return ((intmax_t)va_arg(args, int));
}

/*
 * 	g_fl[0] = '0'
 *	g_fl[1] = ' '
 *	g_fl[3] = '+'
 * 	g_fl[4] = '-'
 */

static size_t		ft_pflnbr(intmax_t n)
{
	int			l;
	int			prefix;
	int			prec;

	l = (n || g_len.p) ? (int)ft_getdigits(n, 10) : 0;
	prefix = ((n < 0 || g_fl[1].set || g_fl[3].set) ? 1 : 0);
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

char				*ft_pfmnbr(va_list args)
{
	intmax_t	n;
	int			dl;
	int			l;
	int			i;
	char		*str;

	n = ft_pfgetdata(args);
	dl = ft_pflnbr(n);
	l = (g_len.w > dl) ? g_len.w : dl;
	str = ft_strnew(l);
	ft_memset(str, ((g_fl[0].set && !g_fl[4].set && !g_len.ps) ? '0' : ' '), l);
	l = (g_fl[4].set) ? dl : l;
	SET_CHAR((g_fl[1].set), str[l - dl], ' ');
	SET_CHAR((g_fl[3].set), str[l - dl], '+');
	SET_CHAR((n < 0), str[l - dl], '-');
	i = (n || g_len.p) ? (int)ft_getdigits(n, 10) : 0;
	while (i-- && (n || g_len.p))
	{
		str[--l] = n % 10 * ((n < 0) ? -1 : 1) + '0';
		n /= 10;
		g_len.p--;
	}
	while (g_len.p-- > 0)
		str[--l] = '0';
	return (str);
}
