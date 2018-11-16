/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfmakestrw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 19:15:16 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/11 18:31:53 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <stdio.h>

extern t_flag	g_fl[];
extern t_len	g_len;
extern char		*g_saved_l;

char	*ft_pfmstrw(va_list args)
{
	wchar_t	*str;
	char	*ret;
	int		cl;
	int		l;
	int		offset;

	str = va_arg(args, wchar_t *);
	if (!str)
		str = L"(null)";
	cl = ft_strsizew(str);
	l = (cl > g_len.w) ? cl : g_len.w;
	ret = ft_strnew(l);
	if (g_fl[0].set && !g_len.ps && !g_fl[4].set)
		ft_memset(ret, '0', l);
	else
		ft_memset(ret, ' ', l);
	offset = l - cl;
	if (g_fl[4].set)
		offset = 0;
	ft_strncpyw(ret + offset, str, cl, ft_strlenw(str));
	return (ret);
}

char	*ft_pfmcharw(va_list args)
{
	wchar_t	wc;
	int		csize;
	char	*ret;
	int		pos;
	int		l;

	wc = va_arg(args, wchar_t);
	csize = ft_charsizew(wc);
	l = (g_len.w > csize) ? g_len.w : csize;
	ret = ft_strnew(l);
	if (g_fl[0].set && !g_len.ps && !g_fl[4].set)
		ft_memset(ret, '0', l);
	else
		ft_memset(ret, ' ', l);
	pos = l - csize;
	if (g_fl[4].set)
		pos = 0;
	ft_utfencode(ret + pos, wc);
	return (ret);
}
