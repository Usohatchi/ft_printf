/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:31:04 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/13 19:38:21 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *ndl)
{
	int		i;
	int		a;
	int		b;

	if (ft_strlen(ndl) == 0)
		return ((char*)hay);
	a = 0;
	while (hay[a])
	{
		i = 0;
		b = a;
		while (ndl[i] && ndl[i] == hay[b])
		{
			b++;
			i++;
		}
		if (!ndl[i])
			return ((char*)(hay + a));
		a++;
	}
	return (NULL);
}
