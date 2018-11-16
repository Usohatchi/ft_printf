/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:23:34 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/13 19:28:09 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ret;

	ret = NULL;
	while (*str)
	{
		if (*str == c)
			ret = (char*)str;
		str++;
	}
	if (*str == c)
		ret = (char*)str;
	return (ret);
}
