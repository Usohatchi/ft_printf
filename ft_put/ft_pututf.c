/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pututf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:52:05 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/11 14:59:35 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_pututf(wchar_t code)
{
	char	buff[4];
	int		bytes;

	bytes = ft_utfencode(buff, code);
	write(1, buff, bytes);
	return (bytes);
}
