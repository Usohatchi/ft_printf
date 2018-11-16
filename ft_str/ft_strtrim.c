/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:37:20 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/17 14:38:45 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isws(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static size_t	ft_firstws(const char *str)
{
	size_t	i;

	i = 0;
	while (ft_isws(str[i++]))
		;
	return (i);
}

static size_t	ft_lastws(const char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (ft_isws(str[i--]))
		;
	return (i + 3);
}

char			*ft_strtrim(const char *str)
{
	size_t	i;
	size_t	l;
	char	*ret;

	if (!str)
		return (NULL);
	if (!ft_strlen(str) || ft_lastws(str) < ft_firstws(str))
		return (ft_strnew(0));
	l = ft_lastws(str) - ft_firstws(str);
	ret = ft_strnew(l);
	if (!ret)
		return (NULL);
	i = 0;
	str += ft_firstws(str) - 1;
	while (i < l)
	{
		ret[i] = *str;
		str++;
		i++;
	}
	return (ret);
}
