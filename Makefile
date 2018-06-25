# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 17:18:00 by kjalloul          #+#    #+#              #
#    Updated: 2018/06/25 18:02:24 by kjalloul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

SRCPATH = ./src/

OBJPATH = ./objs/

IPATHLIB = libft/includes

IPATHGRAPH = libgraph/includes

IPATHXML = libxml/includes

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
		parse_util.c\
		ft_resolve_cercle.c\
		ft_resolve_rect.c\
		line.c\
		plane.c\
		ft_resolve_primitives.c \
		ft_ambiant.c\
		ft_sun.c \
		ft_direct_light.c\
		ft_shade.c\
		math.c\
		ft_resolve_tore.c\
		ft_resolve_triangle.c\
		solve_4thdeg.c\
		ft_throw_rays.c\
		ft_refraction.c\
		ft_texture_load.c\
		ft_texture_coord.c\
		ft_shadow.c\
		ft_save_image.c\
		ft_perturbation.c\
		cut.c\
		ft_sepia.c\
		ft_checkers.c\
		ft_parsing_primitives2.c\
		ft_parsing_options.c\
		ft_initialise_prim.c\
		ft_create_local_prim2.c\
		ft_parsing_texture.c\
		ft_parsing_sin.c\
		ft_refraction_parsing.c\
		ft_parsing_tools.c\
		ft_shadow_shade.c\
		util.c\
		ft_rotate_primitives2.c

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
	make clean -C libxml/
	make clean -C gtk/

LIBFCLEAN:
	make fclean -C libft/
	make fclean -C libgraph/
	make fclean -C minilibx_macos/
	make fclean -C libxml/
	make fclean -C gtk/

$(OBJ): $(OBJPATH)%.o: $(SRCPATH)%.c $(IPATH)$(HEADER)
	gcc $(FLAG) -o $@ -c $< -I$(IPATH) -I$(IPATHLIB) -I$(IPATHGRAPH) -I$(IPATHXML) -I minilibx_macos/

$(NAME): $(OBJ)
	make -C libft
	make -C libgraph
	make -C minilibx_macos
	make -C libxml
	gcc $(FLAG) -o $(NAME) $(OBJ) -Llibft/ -lft -Llibgraph -lgraph -Llibxml/ -lxml -Lminilibx_macos/ -lmlx -framework OpenGL -framework AppKit

clean: LIBCLEAN
	/bin/rm -f $(OBJ)

fclean: clean LIBFCLEAN
	/bin/rm -f $(NAME)

ui: all
	make -C gtk

re: fclean all
