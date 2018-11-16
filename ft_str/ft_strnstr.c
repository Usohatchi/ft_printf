/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:39:20 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/17 18:48:47 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndl, size_t l)
{
	size_t	i;
	size_t	a;
	size_t	b;

	if (ft_strlen(ndl) == 0)
		return ((char*)hay);
	i = 0;
	while (hay[i] && i < l)
	{
		a = 0;
		b = i;
		while (ndl[a] && ndl[a] == hay[b] && i + a < l)
		{
			a++;
			b++;
		}
		if (!ndl[a])
			return ((char*)(hay + i));
		i++;
	}
	return (NULL);
}
