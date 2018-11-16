/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:47:11 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/27 18:52:18 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_countsplit(const char *str, char c)
{
	int		i;

	i = 0;
	while (*str == c)
		str++;
	while (*str)
	{
		str++;
		if (*str == c)
		{
			while (*str == c)
				str++;
			i++;
		}
	}
	if (ft_strlen(str) > 0 && *--str != c)
		i++;
	return (i);
}

static size_t	ft_splitlen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int		ft_checknext(const char **str, char c)
{
	while (**str == c && **str)
		(*str)++;
	if (**str)
		return (1);
	return (0);
}

char			**ft_strsplit(const char *str, char c)
{
	char	**ret;
	int		i;
	int		a;

	if (!str)
		return (NULL);
	ret = malloc((ft_countsplit(str, c) + 1) * sizeof(char*));
	if (!ret)
		return (NULL);
	i = 0;
	while (ft_checknext(&str, c))
	{
		ret[i] = ft_strnew(ft_splitlen(str, c));
		if (!ret[i])
			return (NULL);
		a = 0;
		while (*str != c && *str)
			ret[i][a++] = *str++;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
