/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lookup.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:41:11 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/16 09:50:45 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_LOOKUP_H
# define FT_PRINTF_LOOKUP_H

# include "ft_printf.h"
# define FLAG_S 10
# define FUNC_S 17

int				g_count = 0;
int				g_i = 0;
t_flag			g_fl[] =
{
	{'0', 0},
	{' ', 0},
	{'#', 0},
	{'+', 0},
	{'-', 0},
	{'l', 0},
	{'h', 0},
	{'j', 0},
	{'z', 0},
	{'L', 0},
};
t_len			g_len = {-1, -1, 0};
t_func			g_func[] =
{
	{'s', &(ft_pfmstr), 0, "", ""},
	{'S', &(ft_pfmstrw), 0, "", ""},
	{'p', &(ft_pfmnbru), 16, "0x", "0123456789abcdef"},
	{'d', &(ft_pfmnbr), 10, "", ""},
	{'D', &(ft_pfmnbru), 10, "", "0123456789"},
	{'i', &(ft_pfmnbr), 10, "", ""},
	{'o', &(ft_pfmnbru), 8, "0", "01234567"},
	{'O', &(ft_pfmnbru), 8, "0", "01234567"},
	{'u', &(ft_pfmnbru), 10, "", "0123456789"},
	{'U', &(ft_pfmnbru), 10, "", "0123456789"},
	{'x', &(ft_pfmnbru), 16, "0x", "0123456789abcdef"},
	{'X', &(ft_pfmnbru), 16, "0X", "0123456789ABCDEF"},
	{'c', &(ft_pfmchar), 0, "", ""},
	{'C', &(ft_pfmcharw), 0, "", ""},
	{'b', &(ft_pfmnbru), 2, "", "01"},
	{'%', &(ft_pfmchar), 0, "", ""},
	{'f', &(ft_pfmdbl), 10, "", ""},
};

#endif
