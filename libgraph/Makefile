# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 17:18:00 by kjalloul          #+#    #+#              #
#    Updated: 2018/06/05 19:06:05 by kjalloul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgraph.a

IPATH = includes/

IPATHLIB = ../libft/includes

SRC = ft_fill_img.c\
		ft_create_img.c\
		ft_error.c\
		ft_create_window.c\
		ft_mlx_init.c\
		ft_key_exit.c\
		ft_set_3dpt.c\
		ft_fill_img_rgb.c\
		ft_vect.c\
		ft_vect2.c\
		ft_stb_load_texture.c\
		ft_get_texture_color.c\
		ft_set_color.c\
		ft_get_texture_normal.c\
		ft_read_img_rgb.c

OBJ = $(SRC:%.c=%.o)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(OBJ):%.o: %.c
	gcc $(FLAG) -o $@ -c $< -I$(IPATH) -I$(IPATHLIB)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
