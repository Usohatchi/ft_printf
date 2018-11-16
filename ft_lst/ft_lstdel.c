/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:41:36 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/27 18:56:22 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (alst && *alst)
	{
		tmp = *alst;
		(*del)(tmp->content, tmp->content_size);
		if (tmp->next)
			ft_lstdel(&(tmp->next), (*del));
		free(tmp);
		*alst = NULL;
	}
}
