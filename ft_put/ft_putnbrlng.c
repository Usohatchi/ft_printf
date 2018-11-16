/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlng.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:48:13 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/27 18:51:34 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <limits.h>

void	ft_putnbrlng(long i)
{
	if (i == LONG_MIN)
	{
		write(1, "-", 1);
		ft_putnbrlng(i / -10);
		ft_putchar(i % 10 * -1 + '0');
	}
	else
	{
		if (i < 0)
		{
			i *= -1;
			write(1, "-", 1);
		}
		if (i >= 10)
			ft_putnbrlng(i / 10);
		ft_putchar(i % 10 + '0');
	}
}
