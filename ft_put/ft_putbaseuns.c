/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbaseuns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:48:13 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/30 14:57:27 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "libft.h" */
#include <unistd.h>
#include <stdio.h>

int		ft_putbaseuns(unsigned int i, unsigned int base, int upper)
{
	char	*key;
	int		ret;

	key = (upper) ? "0123456789ABCDEF" : "0123456789abcdef";
	ret = 1;
	if (i >= base)
		ret += ft_putbaseuns(i / base, base, upper);
	write(1, &(key[i % base]), 1);
	return (ret);
}
