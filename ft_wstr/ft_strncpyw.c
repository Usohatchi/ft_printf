/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpyw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:46:24 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/11 15:28:02 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpyw(char *dest, const wchar_t *src, size_t dn, size_t sn)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	while (a < sn && src[a])
	{
		i += ft_utfencode(dest + i, src[a]);
		a++;
	}
	while (i < dn)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
