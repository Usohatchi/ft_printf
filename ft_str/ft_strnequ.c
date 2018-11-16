/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:20:56 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/15 15:23:52 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (!str1 || !str2)
		return (0);
	i = 0;
	while (str1[i] && str2[i] && i < n)
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return (0);
		i++;
	}
	if (i == n || (!str1[i] && !str2[i]))
		return (1);
	return (0);
}
