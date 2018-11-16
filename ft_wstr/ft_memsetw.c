/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsetw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:44:21 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/11 14:43:05 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memsetw(void *str, wchar_t c, size_t n)
{
	wchar_t	*tmp;
	size_t	i;

	i = 0;
	tmp = (wchar_t*)str;
	while (i < n)
	{
		tmp[i] = c;
		i++;
	}
	return (str);
}
