/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:31:25 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/15 16:04:31 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strappend(char *str, char *add, size_t s, size_t c)
{
	size_t i;

	if (s == 0)
		str = (char*)malloc(sizeof(char) * c);
	else
		str = (char*)ft_realloc(str, s, s + c);
	if (!str)
		return (NULL);
	i = 0;
	while (i < c)
	{
		str[s] = add[i];
		s++;
		i++;
	}
	str[s] = '\0';
	return (str);
}
