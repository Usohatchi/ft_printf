/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_carry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:17:34 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/16 12:33:34 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

intmax_t	ft_carry(long double dbl, int prec)
{
	if (prec == 0)
		return ((intmax_t)dbl);
	if (dbl < 0)
	{
		if (ft_carry((dbl - (intmax_t)dbl) * 10, prec - 1) <= -5)
			return ((intmax_t)dbl - 1);
	}
	else
	{
		if (ft_carry((dbl - (intmax_t)dbl) * 10, prec - 1) >= 5)
			return ((intmax_t)dbl + 1);
	}
	return ((intmax_t)dbl);
}
