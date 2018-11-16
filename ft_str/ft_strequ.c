/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:12:22 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/23 21:12:07 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *str1, const char *str2)
{
	if (!str1 || !str2)
		return (0);
	while (*str1 && *str2)
		if ((unsigned char)*str1++ != (unsigned char)*str2++)
			return (0);
	if (!*str1 && !*str2)
		return (1);
	return (0);
}
