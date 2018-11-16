/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 21:25:23 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/22 16:33:54 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	int		i;
	int		l;
	int		neg;
	char	*ret;

	i = (int)ft_getdigits(n, 10);
	ret = ft_strnew(i + 1);
	neg = 1;
	l = 0;
	if (!ret)
		return (NULL);
	if (n < 0)
		neg *= -1;
	while (--i >= l)
	{
		ret[i] = (n % 10) * neg + '0';
		n /= 10;
	}
	if (neg == -1)
		ret[0] = '-';
	return (ret);
}
