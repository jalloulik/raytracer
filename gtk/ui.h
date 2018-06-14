/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 10:22:53 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 12:05:51 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include <gtk/gtk.h>
# include <libft.h>
# include <stdlib.h>
# define SPHERE 0
# define CONE 1
# define PLAN 2
# define CYLINDRE 3
# define LIGHT 4
# define AMBIANTE 5
# define SUN 6
# define CAM 7

typedef struct		s_3d
{
	int				x;
	int				y;
	int				z;
}					t_3d;

typedef struct		s_2d
{
	int				x;
	int				y;
}					t_2d;

typedef struct		s_refract
{
	char			on_off;
	char			*material;
	int				pourcent;
}					t_refract;

typedef struct		s_reflect
{
	char			on_off;
	int				pourcent;
}					t_reflect;

typedef struct		s_texture
{
	char			on_off;
	char			*name;
	t_2d			move;
	t_2d			scale;
}					t_texture;

typedef struct		s_sinus
{
	char			on_off;
	t_2d			sin_x;
	t_2d			sin_y;
	t_2d			sin_z;
}					t_sinus;

typedef struct		s_checker
{
	char			on_off;
	t_2d			move;
	t_2d			scale;
}					t_checker;

typedef struct		s_elem
{
	char			*name;
	GtkTreeIter		iter;
	char			type;
	t_3d			pos;
	t_3d			translation;
	t_3d			vec;
	t_3d			rot;
	int				angle_rot;
	t_3d			color;
	int				angle;
	int				rad;
	char			specular;
	t_reflect		reflect;
	t_refract		refract;
	t_texture		tex_c;
	t_texture		tex_n;
	t_sinus			sinus;
	t_checker		checker;
	struct s_elem	*next;
}					t_elem;

# include "interface.h"

typedef struct		s_event_entry
{
	t_interface		*inter;
	int				*value;
	char			**value_char;
	GtkTreeIter		iter;
	int				index1;
	int				index2;
	char			*p_text1;
	char			*p_text2;
}					t_event_entry;

void				ft_colonne0(t_interface *inter);
void				ft_colonne1(t_interface *inter);
void				ft_colonne2(t_interface *inter);
void				ft_colonne3(t_interface *inter);
void				ft_colonne4(t_interface *inter);
void				ft_colonne5(t_interface *inter);

void				ft_set_data(t_interface *inter, t_elem *elem);
void				ft_set_3d_entry(t_3d_button *entry, t_3d elem);
void				ft_set_2d_entry(t_2d_button *entry, t_2d elem);
void				ft_set_1d_entry_int(t_1d_button *entry, int elem);
void				ft_set_1d_entry_char(t_1d_button *entry, char *elem);
void				ft_set_3d(t_3d *elem, int x, int y, int z);
void				ft_set_2d(t_2d *elem, int x, int y);

void				ft_add_list(t_elem *elem);
void				ft_function_test(GtkWidget *widget, gpointer data);
void				ft_entry_value(GtkWidget *widget, gpointer data);
GtkWidget			*ft_button(GtkWidget *grid, char *label);
void				ft_interface(t_interface *inter, GtkWidget *window);
void				ft_iter(GtkTreeIter *iter, GtkListStore *list,
		int ind, char *label);
t_elem				*ft_select_elem(t_interface *inter);
void				ft_switch(t_1d_button *swit, GtkWidget *container, char *name);
void				ft_select_elem_actif(GtkWidget *widget, gpointer data);
void				ft_active_switch(GtkWidget *widget, GParamSpec *pspec,
		gpointer data);
void				ft_event(t_event_entry *e, t_interface *inter);

void				ft_init(t_interface *inter);
void				ft_init_fix(t_interface *inter);
void				ft_init_effect(t_interface *inter);
void				ft_init_elem(t_elem *elem);
void				ft_init_sinus(t_interface *inter);
void				ft_init_checker(t_interface *inter);
void				ft_init_list_e(t_interface *inter);
void				ft_init_show(t_interface *inter);
void				ft_init_3d_button(t_3d_button *button);
void				ft_init_2d_button(t_2d_button *button);
void				ft_init_1d_button(t_1d_button *button);

void				ft_create_sphere(GtkWidget *widget, gpointer data);
void				ft_create_cone(GtkWidget *widget, gpointer data);
void				ft_create_cylindre(GtkWidget *widget, gpointer data);
void				ft_create_plan(GtkWidget *widget, gpointer data);

void				ft_3d_button(t_3d_button *button, GtkWidget *container, char *name);
void				ft_2d_button(t_2d_button *button, GtkWidget *container, char *name);
void				ft_1d_button(t_1d_button *button, GtkWidget *container, char *name);

void				ft_show_reflect(t_interface *inter,  GtkWidget *widget);
void				ft_show_refract(t_interface *inter,  GtkWidget *widget);
void				ft_show_texture_c(t_interface *inter,  GtkWidget *widget);
void				ft_show_texture_n(t_interface *inter,  GtkWidget *widget);
void				ft_show_checker(t_interface *inter,  GtkWidget *widget);
void				ft_show_sinus(t_interface *inter,  GtkWidget *widget);

void				ft_type_entry_1(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter);
void				ft_type_entry_2(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter);
void				ft_type_entry_3(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter);

#endif
