/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsizew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:24:54 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/11 15:37:26 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strsizew(wchar_t *str)
{
	int ret;

	ret = 0;
	while (*str)
	{
		if (*str > 0x10FFFF)
			return (ret);
		else if (*str <= 0x7F)
			ret += 1;
		else if (*str <= 0x7FF)
			ret += 2;
		else if (*str <= 0xFFFF)
			ret += 3;
		else
			ret += 4;
		str++;
	}
	return (ret);
}
