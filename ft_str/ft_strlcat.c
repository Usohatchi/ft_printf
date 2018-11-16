/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:07:37 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/26 20:36:18 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, char *restrict src, size_t n)
{
	size_t	i;
	size_t	a;
	size_t	len;

	i = 0;
	while (dst[i] && i < n)
		i++;
	if (i == n)
		return (i + ft_strlen(src));
	len = i;
	a = 0;
	while (src[a])
	{
		if (i < n - 1)
		{
			dst[i] = src[a];
			i++;
		}
		a++;
	}
	dst[i] = '\0';
	return (len + a);
}
