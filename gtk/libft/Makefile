# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 17:18:00 by kjalloul          #+#    #+#              #
#    Updated: 2017/12/12 17:43:54 by kjalloul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

IPATH = includes/

SRC = ft_putchar.c\
	  ft_putstr.c\
	  ft_putendl.c\
	  ft_putnbr.c\
	  ft_putnbrendl.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_isdigit.c\
	  ft_isalnum.c\
	  ft_isascii.c\
	  ft_isalpha.c\
	  ft_isprint.c\
	  ft_strlen.c\
	  ft_atoi.c\
	  ft_strstr.c\
	  ft_strnstr.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  ft_strcmp.c\
	  ft_strncmp.c\
	  ft_strcpy.c\
	  ft_strncpy.c\
	  ft_strcat.c\
	  ft_strncat.c\
	  ft_strlcat.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_memset.c\
	  ft_bzero.c\
	  ft_memcpy.c\
	  ft_memccpy.c\
	  ft_memmove.c\
	  ft_memcmp.c\
	  ft_memchr.c\
	  ft_memalloc.c\
	  ft_memdel.c\
	  ft_strnew.c\
	  ft_strdel.c\
	  ft_strclr.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strsub.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_strdup.c\
	  ft_strsplit.c\
	  ft_itoa.c\
	  ft_lstnew.c\
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_lstadd.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_is_char_in_str.c\
	  ft_count_char.c\
	  get_next_line.c

OBJ = $(SRC:%.c=%.o)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(OBJ):%.o: %.c
	gcc $(FLAG) -o $@ -c $< -I$(IPATH)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
