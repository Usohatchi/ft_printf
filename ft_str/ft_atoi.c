/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 21:47:08 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/27 18:49:47 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int ret;
	int	neg;

	ret = 0;
	neg = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		neg *= -1;
	}
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (ret * neg);
		ret = (*str - '0') + ret * 10;
		str++;
	}
	return (ret * neg);
}
