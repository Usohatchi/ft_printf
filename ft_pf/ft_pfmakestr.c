/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfmakestr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 19:15:16 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/11 18:50:35 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

extern t_func	g_func[];
extern t_flag	g_fl[];
extern t_len	g_len;
extern int		g_i;

char	*ft_pfmstr(va_list args)
{
	char	*str;
	char	*ret;
	int		cl;
	int		l;
	int		offset;

	if (g_fl[5].set)
		return (ft_pfmstrw(args));
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	cl = ((int)ft_strlen(str) > g_len.p && g_len.p != -1)
		? g_len.p : (int)ft_strlen(str);
	l = (cl > g_len.w) ? cl : g_len.w;
	ret = ft_strnew(l);
	if (g_fl[0].set && !g_len.ps && !g_fl[4].set)
		ft_memset(ret, '0', l);
	else
		ft_memset(ret, ' ', l);
	offset = l - cl;
	if (g_fl[4].set)
		offset = 0;
	ft_strncpy(ret + offset, str, cl);
	return (ret);
}

char	*ft_pfmchar(va_list args)
{
	char	*ret;
	int		pos;
	int		l;

	if (g_fl[5].set)
		return (ft_pfmcharw(args));
	l = (g_len.w > 1) ? g_len.w : 1;
	ret = ft_strnew(l);
	if (g_fl[0].set && !g_len.ps && !g_fl[4].set)
		ft_memset(ret, '0', l);
	else
		ft_memset(ret, ' ', l);
	pos = l - 1;
	if (g_fl[4].set)
		pos = 0;
	if (g_func[g_i].f == '%')
		ret[pos] = '%';
	else
		ret[pos] = va_arg(args, int);
	return (ret);
}
