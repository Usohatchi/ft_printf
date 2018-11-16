/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utfencode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:24:54 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/11 15:09:47 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_utfencode(char *buff, wchar_t code)
{
	if (code > 0x10FFFF)
		return (0);
	if (code <= 0x7F)
	{
		buff[0] = code;
		return (1);
	}
	else if (code <= 0x7FF)
	{
		buff[0] = 0xC0 | (code >> 6);
		buff[1] = 0x80 | (code & 0x3F);
		return (2);
	}
	else if (code <= 0xFFFF)
	{
		buff[0] = 0xE0 | (code >> 12);
		buff[1] = 0x80 | ((code >> 6) & 0x3F);
		buff[2] = 0x80 | (code & 0x3F);
		return (3);
	}
	buff[0] = 0xF0 | (code >> 18);
	buff[1] = 0x80 | ((code >> 12) & 0x3F);
	buff[2] = 0x80 | ((code >> 6) & 0x3F);
	buff[3] = 0x80 | (code & 0x3F);
	return (4);
}
