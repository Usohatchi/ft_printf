# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 12:11:18 by otahirov          #+#    #+#              #
#    Updated: 2018/11/16 13:01:10 by eito-fis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

P_IS = ft_is
_SRC_IS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c
SRC_IS = $(patsubst %,$(P_IS)/%,$(_SRC_IS))
P_LST = ft_lst
_SRC_LST = ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
		   ft_lstnew.c
SRC_LST = $(patsubst %,$(P_LST)/%,$(_SRC_LST))
P_MEM = ft_mem
_SRC_MEM = ft_memalloc.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_realloc.c \
		   ft_memccpy.c ft_memcmp.c ft_memdel.c ft_memset.c
SRC_MEM = $(patsubst %,$(P_MEM)/%,$(_SRC_MEM))
P_PUT = ft_put
_SRC_PUT = ft_putbaseuns.c ft_putchar_fd.c ft_putnbr.c ft_putnbrlng.c ft_putstr.c \
		   ft_putbaseunslng.c ft_putendl.c ft_putnbr_fd.c ft_putnbrlngc.c ft_putstr_fd.c \
		   ft_putchar.c ft_putendl_fd.c ft_putnbrc.c ft_putnbrlnguns.c ft_pututf.c
SRC_PUT = $(patsubst %,$(P_PUT)/%,$(_SRC_PUT))
P_STR = ft_str
_SRC_STR = ft_atoi.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strncat.c \
		   ft_strnstr.c ft_strtrim.c ft_itoa.c ft_strclr.c ft_strequ.c \
		   ft_strlcat.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_reverse.c \
		   ft_strcmp.c ft_strequone.c ft_strlen.c ft_strncpy.c ft_strsplit.c \
		   ft_toupper.c ft_strappend.c ft_strcpy.c ft_striter.c ft_strmap.c \
		   ft_strnequ.c ft_strstr.c ft_strcat.c ft_strdel.c ft_striteri.c \
		   ft_strmapi.c ft_strnew.c ft_strsub.c
SRC_STR = $(patsubst %,$(P_STR)/%,$(_SRC_STR))
P_GNL = ft_gnl
_SRC_GNL = get_next_line.c
SRC_GNL = $(patsubst %,$(P_GNL)/%,$(_SRC_GNL))
P_NBR = ft_nbr
_SRC_NBR = ft_bzero.c ft_getdigits.c ft_getdigitsuns.c ft_power.c ft_sqrt.c
SRC_NBR = $(patsubst %,$(P_NBR)/%,$(_SRC_NBR))
P_PF = ft_pf
_SRC_PF = ft_pfmakenbr.c ft_pfmakenbru.c ft_pfmakestr.c ft_pfmakestrw.c ft_printf.c \
		  ft_pfmakedbl.c
SRC_PF = $(patsubst %,$(P_PF)/%,$(_SRC_PF))
P_WSTR = ft_wstr
_SRC_WSTR = ft_memsetw.c ft_strlenw.c ft_strncpyw.c ft_strneww.c ft_utfencode.c \
			ft_strsizew.c ft_charsizew.c
SRC_WSTR = $(patsubst %,$(P_WSTR)/%,$(_SRC_WSTR))
P_DBL = ft_dbl
_SRC_DBL = ft_carry.c ft_convert.c
SRC_DBL = $(patsubst %,$(P_DBL)/%,$(_SRC_DBL))

SRC = $(SRC_IS) $(SRC_LST) $(SRC_MEM) $(SRC_PUT) $(SRC_STR) \
	  $(STR_GNL) $(SRC_NBR) $(SRC_PF) $(SRC_WSTR) $(SRC_DBL)
_SRCO = $(SRC:%.c=%.o)
SRCO = $(notdir $(_SRCO))

INC = includes/

CFLAGS = -Wall -Wextra -Werror
CLANG = gcc

all : $(NAME)

$(NAME) :
	@$(CLANG) $(CFLAGS) -c $(SRC) -I $(INC)
	@ar rc $(NAME) $(SRCO)
	@ranlib $(NAME)
	@echo "$(NAME) was compiled!"

clean :
	@rm $(SRCO)
	@echo "Object files were cleaned!"

fclean :
	@rm -f $(NAME)
	@echo "$(NAME) was removed!"

re : fclean all
