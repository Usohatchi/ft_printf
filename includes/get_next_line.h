/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:41:11 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/27 13:45:36 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 2
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	int				fd;
	int				linel;
	int				buffl;
	char			buff[BUFF_SIZE];
	struct s_list	*next;
}				t_list;

char			*ft_strncpy(char *dst, const char *str, size_t n);
void			*ft_strappend(void *str, void *add, size_t s, size_t a);
int				get_next_line(const int fd, char **line);

#endif
