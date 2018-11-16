/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:59:46 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/13 17:13:47 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict str1, char *restrict str2)
{
	size_t i;
	size_t a;

	i = ft_strlen(str1);
	a = 0;
	while (str2[a])
	{
		str1[i] = str2[a];
		a++;
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
