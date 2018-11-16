/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:17:34 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/16 13:12:22 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_convert(long double dbl, int prec)
{
	uintmax_t n;

	n = 0;
	while (prec-- >= 0)
	{
		n *= 10;
		n += (intmax_t)dbl;
		dbl -= (intmax_t)dbl;
		dbl *= 10;
	}
	if ((intmax_t)(dbl * 10) > 5)
		n++;
	return (n);
}
