NAME = test

SRCPATH = ./

OBJPATH = ./

IPATHLIB = libft/includes

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
	src/interface/interface.c \
	src/interface/colonne0.c \
	src/interface/colonne1.c \
	src/interface/colonne2.c \
	src/interface/colonne3.c \
	src/interface/colonne4.c \
	src/interface/colonne5.c \
	src/interface/3d_button.c \
	src/interface/2d_button.c \
	src/interface/1d_button.c \
	src/interface/switch_creation.c \
	src/ft_list.c \
	src/fonction_elem.c \
	src/set_data.c \
	src/set_entry.c \
	src/user_values.c \
	src/active_switch.c \
	src/show_option.c \
	src/event.c \
	src/type.c \

OBJ = $(SRC:%.c=$(OBJPATH)%.o)

SRCF = $(SRCPATH)$(SRC)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

LIB:
	make -C libft/

LIBCLEAN:
	make clean -C libft/

LIBFCLEAN:
	make fclean -C libft/

$(OBJ): $(OBJPATH)%.o: $(SRCPATH)%.c $(IPATH)$(HEADER)
	gcc $(FLAG) -o $@ -c $< -I$(IPATH) -I$(IPATHLIB) `pkg-config --cflags gtk+-3.0`

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAG) -o $(NAME) $(OBJ) -Llibft/ -lft `pkg-config --libs gtk+-3.0`

clean: LIBCLEAN
	/bin/rm -f $(OBJ)

fclean: clean LIBFCLEAN
	/bin/rm -f $(NAME)

re: fclean all