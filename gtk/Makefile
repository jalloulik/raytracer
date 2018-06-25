NAME = ui

SRCPATH = ./

OBJPATH = ./

IPATHLIB = ../libft/includes

IPATH = ./

HEADER = ui.h

SRC = src/main.c \
	src/init/init.c \
	src/init/init_fix.c \
	src/init/init_elem.c \
	src/init/init_effect.c \
	src/init/init_sinus.c \
	src/init/init_checker.c \
	src/init/init_list_e.c \
	src/init/init_show.c \
	src/init/init_show2.c \
	src/init/init_show_cut.c \
	src/init/init_cut.c \
	src/interface/interface.c \
	src/interface/colonne0.c \
	src/interface/colonne1.c \
	src/interface/colonne2.c \
	src/interface/colonne3.c \
	src/interface/colonne4.c \
	src/interface/colonne5.c \
	src/interface/colonne6.c \
	src/interface/colonne7.c \
	src/interface/colonne8.c \
	src/interface/colonne9.c \
	src/interface/d3_button.c \
	src/interface/d2_button.c \
	src/interface/d1_button.c \
	src/interface/switch_creation.c \
	src/show_option/show_option.c \
	src/show_option/show_option_2.c \
	src/show_option/show_option_prim.c \
	src/show_option/show_option_prim_2.c \
	src/show_option/show_sinus.c \
	src/show_option/show_texture.c \
	src/show_option/set_data_show.c \
	src/show_option/show_cut.c \
	src/show_option/show_switch.c \
	src/show_option/show_switch_sinus.c \
	src/show_option/show_switch_texture.c \
	src/ft_list.c \
	src/fonction_elem.c \
	src/fonction_elem_2.c \
	src/fonction_elem_3.c \
	src/set_data.c \
	src/set_data_entry.c \
	src/set_entry.c \
	src/entry_values.c \
	src/active_switch.c \
	src/event.c \
	src/event_entry.c \
	src/event_entry_cut.c \
	src/type_entry.c \
	src/type_entry_cut.c \
	src/render.c \
	src/parse_camera.c \
	src/parse_light.c \
	src/parse_prim_3d.c \
	src/parse_prim_2d.c \
	src/parse_functions.c \
	src/parse_function2.c \
	src/parse_function3.c \
	src/parse_function4.c \
	src/parse_function5.c \
	src/parse_cut.c \

OBJ = $(SRC:%.c=$(OBJPATH)%.o)

SRCF = $(SRCPATH)$(SRC)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(OBJ): $(OBJPATH)%.o: $(SRCPATH)%.c $(IPATH)$(HEADER)
	gcc $(FLAG) -o $@ -c $< -I$(IPATH) -I$(IPATHLIB) `pkg-config --cflags gtk+-3.0`

$(NAME): $(OBJ)
	gcc $(FLAG) -o $(NAME) $(OBJ) -L../libft/ -lft `pkg-config --libs gtk+-3.0`

clean:
	/bin/rm -f $(OBJ)

fclean:
	/bin/rm -f $(NAME)

re: fclean all