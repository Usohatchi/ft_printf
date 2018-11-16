/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:48:13 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/29 16:44:08 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <unistd.h>

int		ft_putnbrc(int n)
{
	if (n == INT_MIN)
	{
		ft_putnbr(n / -10);
		ft_putchar((n % 10) * -1 + '0');
	}
	else
	{
		if (n < 0)
			n *= -1;
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	return (ft_getdigits(n, 10));
}
