# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 17:18:00 by kjalloul          #+#    #+#              #
#    Updated: 2018/05/28 15:25:35 by kjalloul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

SRCPATH = ./src/

OBJPATH = ./

IPATHLIB = libft/includes

IPATHGRAPH = libgraph/includes

IPATH = ./

HEADER = rtv1.h

SRC = main.c\
		ft_init_scene.c\
		ft_color_universe.c\
		ft_vector_tools.c\
		ft_resolve_sphere.c\
		ft_resolve_plane.c\
		ft_keyhooks.c\
		ft_tools.c\
		ft_resolve_cylindre.c\
		ft_parsing.c\
		ft_camera.c\
		ft_spots.c\
		ft_resolve_cone.c\
		ft_quaternions.c\
		ft_calculate_normal_primitives.c\
		ft_quater_tools.c\
		ft_global_local_swap.c\
		ft_vector_math.c\
		ft_parsing_primitives.c\
		ft_rotate_primitives.c\
		ft_create_local_prim.c\
		ft_check_if_lit.c\
		ft_errors.c\
		ft_resolve_primitives.c \
		ft_ambiant.c\
		ft_sun.c \
		ft_direct_light.c\
		ft_shade.c\
		ft_throw_rays.c\
		ft_refraction.c\
		ft_texture_load.c\
		ft_texture_coord.c

OBJ = $(SRC:%.c=$(OBJPATH)%.o)

SRCF = $(SRCPATH)$(SRC)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

LIB:
	make -C libft/

LIBCLEAN:
	make clean -C libft/
	make clean -C libgraph/
	make clean -C minilibx_macos/

LIBFCLEAN:
	make fclean -C libft/
	make fclean -C libgraph/
	make fclean -C minilibx_macos/

$(OBJ): $(OBJPATH)%.o: $(SRCPATH)%.c $(IPATH)$(HEADER)
	gcc $(FLAG) -o $@ -c $< -I$(IPATH) -I$(IPATHLIB) -I$(IPATHGRAPH) -I minilibx_macos/

$(NAME): $(OBJ)
	make -C libft
	make -C libgraph
	make -C minilibx_macos
	gcc $(FLAG) -o $(NAME) $(OBJ) -Llibft/ -lft -Llibgraph -lgraph -Lminilibx_macos/ -lmlx -framework OpenGL -framework AppKit

clean: LIBCLEAN
	/bin/rm -f $(OBJ)

fclean: clean LIBFCLEAN
	/bin/rm -f $(NAME)

re: fclean all
