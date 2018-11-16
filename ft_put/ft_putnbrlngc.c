/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlngc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:48:13 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/29 16:43:56 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <limits.h>

int		ft_putnbrlngc(long i)
{
	if (i == LONG_MIN)
	{
		ft_putnbrlng(i / -10);
		ft_putchar(i % 10 * -1 + '0');
	}
	else
	{
		if (i < 0)
			i *= -1;
		if (i >= 10)
			ft_putnbrlng(i / 10);
		ft_putchar(i % 10 + '0');
	}
	return (ft_getdigits(i, 10));
}
