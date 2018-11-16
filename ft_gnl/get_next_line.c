/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:42:38 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/27 14:28:17 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

t_list	*ft_newfile(const int fd)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	ret->fd = fd;
	ret->linel = 0;
	ret->buffl = 0;
	ret->next = NULL;
	return (ret);
}

t_list	*ft_findfile(const int fd, t_list *lst)
{
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_list	*ft_addfile(t_list *lst, t_list *add)
{
	if (lst && add)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = add;
	}
	return (add);
}

int		ft_checkbuff(ssize_t br, char *b, t_list *lst, char **line)
{
	ssize_t		i;

	if (br <= 0 && lst->linel == 0)
		return (br);
	else if (br == 0)
	{
		*line = ft_strappend(*line, "\0", lst->linel, sizeof(char));
		lst->linel = 0;
		lst->buffl = 0;
		return (1);
	}
	i = 0;
	while (i < br && b[i] != '\n')
		i++;
	*line = ft_strappend(*line, b, lst->linel, i);
	lst->linel += i;
	if (i == br)
		return (-2);
	*line = ft_strappend(*line, "\0", lst->linel, sizeof(char));
	ft_strncpy(lst->buff, b + i + 1, br - i - 1);
	lst->buffl = br - i - 1;
	lst->linel = 0;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*tmp;
	char			b[BUFF_SIZE];
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (!lst)
		lst = ft_newfile(fd);
	if (ft_findfile(fd, lst))
	{
		tmp = ft_findfile(fd, lst);
		if (ft_checkbuff(tmp->buffl, tmp->buff, tmp, line) == 1)
			return (1);
	}
	else
		tmp = ft_addfile(lst, ft_newfile(fd));
	ret = -2;
	while (ret == -2)
		ret = ft_checkbuff(read(fd, b, BUFF_SIZE), b, tmp, line);
	return (ret);
}
