/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:04:23 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/13 17:06:13 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict str1, char *restrict str2, size_t n)
{
	size_t	i;
	size_t	a;

	i = ft_strlen(str1);
	a = 0;
	while (str2[a] && a < n)
	{
		str1[i] = str2[a];
		a++;
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
