/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:50:28 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/09 15:05:55 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int i)
{
	int	start;
	int	end;
	int	ret;
	int mid;

	if (i == 0 || i == 1)
		return (i);
	start = 0;
	end = i / 2;
	ret = 0;
	while (start < end)
	{
		mid = (start + end) / 2;
		if (i == mid * mid)
			return (mid);
		if (i > mid * mid)
		{
			start = mid + 1;
			ret = mid;
		}
		else
			end = mid;
	}
	return (ret + 1);
}
