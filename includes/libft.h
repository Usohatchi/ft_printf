/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:07:58 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/16 13:00:47 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <strings.h>
# include <stdint.h>
# include <stddef.h>
# define BUFF_SIZE 1024

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_putchar(char c);
int				ft_pututf(wchar_t c);
void			ft_putstr(const char *str);
void			ft_putendl(const char *str);
void			ft_putnbr(int i);
int				ft_putnbrc(int i);
void			ft_putnbrlng(long i);
int				ft_putnbrlngc(long i);
void			ft_putnbrlnguns(unsigned long i);
int				ft_putbaseuns(unsigned int i, unsigned int base, int u);
int				ft_putbaseunslng(unsigned long i, unsigned long base, int u);
void			ft_putaddrs(int i);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
size_t			ft_strlen(const char *str);
size_t			ft_strlenw(const wchar_t *str);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strncpyw(char *dest, const wchar_t *src,
		size_t dn, size_t sn);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
void			*ft_memset(void *str, int c, size_t n);
void			*ft_memsetw(void *str, wchar_t c, size_t n);
void			ft_bzero(char *str, int n);
void			*ft_memcpy(void *restrict dst,
		const void *restrict src, size_t n);
void			*ft_memccpy(void *restrict dst,
		const void *restrict src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t l);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
char			*ft_strcat(char	*restrict str1, char *restrict str2);
char			*ft_strncat(char *restrict str1, char *restrict str2, size_t n);
size_t			ft_strlcat(char *restrict dst, char *restrict src, size_t n);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *hay, const char *ndl);
char			*ft_strnstr(const char *hay, const char *ndl, size_t l);
void			*ft_memalloc(size_t size);
void			ft_memdel(void	**ap);
char			*ft_strnew(size_t size);
wchar_t			*ft_strneww(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *str);
void			ft_striter(char *str, void (*f)(char*));
void			ft_striteri(char *str, void (*f)(unsigned int, char*));
char			*ft_strmap(const char *str, char (*f)(char));
char			*ft_strmapi(const char *str, char (*f)(unsigned int, char));
int				ft_strequ(const char *str1, const char *str2);
int				ft_strnequ(const char *str1, const char *str2, size_t n);
int				ft_strequone(const char *str1, const char *str2);
char			*ft_strsub(const char *str, unsigned int start, size_t l);
char			*ft_strjoin(const char *str1, const char *str2);
char			*ft_strtrim(const char *str);
char			**ft_strsplit(const char *str, char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putendl_fd(const char *str, int fd);
void			ft_putnbr_fd(int n, int fd);
size_t			ft_getdigits(intmax_t n, int base);
size_t			ft_getdigitsuns(uintmax_t n, int base);
int				ft_power(int base, int pwr);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			*ft_realloc(void *ptr, size_t cur, size_t l);
char			*ft_strappend(char *str, char *add, size_t cur, size_t f);
int				ft_sqrt(int i);
size_t			ft_utfencode(char *buff, int code);
size_t			ft_charsizew(wchar_t wc);
size_t			ft_strsizew(wchar_t *str);
intmax_t		ft_carry(long double dbl, int prec);
uintmax_t		ft_convert(long double dbl, int prec);

#endif
