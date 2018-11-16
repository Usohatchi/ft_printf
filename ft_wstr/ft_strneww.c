/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strneww.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:42:15 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/07 14:40:21 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

wchar_t	*ft_strneww(size_t size)
{
	wchar_t	*ret;
	size_t	i;

	ret = (wchar_t*)malloc((size + 1) * sizeof(wchar_t));
	if (!ret)
		return (ret);
	i = 0;
	while (i <= size + 1)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}
