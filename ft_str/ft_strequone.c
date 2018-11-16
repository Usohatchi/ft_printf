/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:12:22 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/23 21:21:44 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequone(const char *str1, const char *str2)
{
	if (!str1 || !str2)
		return (0);
	while (*str1 && *str2)
		if ((unsigned char)*str1++ != (unsigned char)*str2++)
			return (0);
	if (!*str1)
		return (1);
	return (0);
}
