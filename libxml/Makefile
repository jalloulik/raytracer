# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 19:08:56 by mfrisby           #+#    #+#              #
#    Updated: 2018/06/15 18:09:36 by mfrisby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libxml.a

SRCPATH = ./

IPATH = ./includes/

OBJPATH = ./

HEADER = libxml.h

IPATHLIB = ../libft/includes

SRC = 	open_file.c\
		read_file.c\
		get_const_balise.c\
		xmlp.c\
		node_parser.c\
		get_balise_name.c\
		get_balise_content.c\
		is_balise_closed.c\
		init_node.c\
		xmlp_get_node.c\
		xmlp_get_next_node.c\
		xmlp_get_node_content.c\
		xmlp_get_child_node_content.c\
		xmlp_split_node_content.c

OBJ = $(SRC:%.c=$(OBJPATH)%.o)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(OBJ): $(OBJPATH)%.o: $(SRCPATH)%.c $(IPATH)$(HEADER)
	gcc $(FLAG) -o $@ -c $< -I$(IPATH) -I$(IPATHLIB)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
