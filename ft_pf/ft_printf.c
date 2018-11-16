/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:55:51 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/16 09:57:27 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_lookup.h"
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>

static void		ft_globalclean(void)
{
	int		i;

	i = 0;
	while (i < FLAG_S)
	{
		g_fl[i].set = 0;
		i++;
	}
	g_len.w = -1;
	g_len.p = -1;
	g_len.ps = 0;
	g_i = 0;
}

const char		*ft_setd(const char *str, const char *f, va_list args)
{
	if (str != f && *(f - 1) == '.')
		g_len.ps = 1;
	if (IS_DIGIT(*f))
	{
		if (*f == '0')
			g_fl[0].set = 1;
		if (str != f && *(f - 1) == '.')
			g_len.p = ft_atoi(f);
		else if (ft_atoi(f) > 0)
			g_len.w = ft_atoi(f);
		while (IS_DIGIT(*f))
			f++;
	}
	else if (*f == '*')
	{
		if (str != f && *(f - 1) == '.')
			g_len.p = va_arg(args, int);
		else
			g_len.w = va_arg(args, int);
		f++;
	}
	else if (*f == '.')
		if (!ft_isdigit(*(++f)))
			g_len.p = 0;
	return (f);
}

/*
 *	g_fl[0] = '0'
 *	g_fl[4] = '-'
 */

const char		*ft_putformat(const char *format, va_list args)
{
	size_t	l;
	char	*str;

	LOOKUP(g_func[g_i].f, *format, g_i, FUNC_S);
	str = (*(g_func[g_i].fmake))(args);
	l = ft_strlen(str);
	if (g_func[g_i].f == 'c' || g_func[g_i].f == 'C')
	{
		if (g_func[g_i].f == 'c' && !g_fl[5].set)
			l = (g_len.w == -1 || !g_len.w) ? 1 : g_len.w;
		else
		{
			if (g_fl[4].set && !str[0])
				l = (g_len.w == -1 || !g_len.w) ? 1 : g_len.w;
			else if ((int)l < g_len.w)
				l = g_len.w;
			else if (!l)
				l = 1;
		}
	}
	g_count += write(1, str, l);
	free(str);
	return (format + 1);
}

const char		*ft_setformat(const char *format, va_list args)
{
	const char	*str;
	int			i;

	str = format;
	while (*format)
	{
		if (IS_DIGIT(*format) || *format == '*' || *format == '.')
			format = ft_setd(str, format, args);
		else if (IS_FLAG(*format))
		{
			i = 0;
			LOOKUP(*format, g_fl[i].f, i, FLAG_S);
			g_fl[i].set += 1;
			format += 1;
		}
		else if (IS_SPEC(*format))
			return (ft_putformat(format, args));
		else
		{
			g_count += write(1, format, 1);
			return (format + 1);
		}
	}
	return (format);
}

int				ft_printf(const char *format, ...)
{
	int		a;
	va_list	args;
	char	print[BUFF_SIZE];

	a = 0;
	g_count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' || a == BUFF_SIZE)
		{
			g_count += write(1, print, a);
			a = 0;
			if (*format == '%')
			{
				ft_globalclean();
				format = ft_setformat(++format, args);
			}
		}
		else
			print[a++] = *format++;
	}
	g_count += write(1, print, a);
	va_end(args);
	return (g_count);
}
