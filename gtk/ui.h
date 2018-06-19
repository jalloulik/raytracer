/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 10:22:53 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/19 16:07:00 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include <gtk/gtk.h>
# include <libft.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define SPHERE 0
# define CONE 1
# define PLAN 2
# define CYLINDRE 3
# define SPOT 4
# define AMBIANT 5
# define SUN 6
# define CAM 7
# define CARRE 8
# define CERCLE 9
# define TORRE 10
# define TRIANGLE 11
# include "elem.h"
# include "interface.h"

typedef struct		s_event_entry
{
	t_interface		*inter;
	int				*value;
	char			**value_char;
	GtkTreeIter		iter;
	char			*p_text1;
	char			*p_text2;
}					t_event_entry;

void				ft_colonne0(t_interface *inter);
void				ft_colonne1(t_interface *inter);
void				ft_colonne2(t_interface *inter);
void				ft_colonne3(t_interface *inter);
void				ft_colonne4(t_interface *inter);
void				ft_colonne5(t_interface *inter);
void				ft_colonne6(t_interface *inter);

void				ft_set_3d_entry(t_3d_button *entry, t_3d elem);
void				ft_set_2d_entry(t_2d_button *entry, t_2d elem);
void				ft_set_1d_entry_int(t_1d_button *entry, int elem);
void				ft_set_1d_entry_char(t_1d_button *entry, char *elem);
void				ft_set_3d(t_3d *elem, int x, int y, int z);
void				ft_set_2d(t_2d *elem, int x, int y);
void				ft_set_data_show(t_interface *inter, t_elem *elem);

void				ft_add_list(t_elem *elem);
void				ft_function_test(GtkWidget *widget, gpointer data);
void				ft_entry_value(GtkWidget *widget, gpointer data);
GtkWidget			*ft_button(GtkWidget *grid, char *label);
void				ft_interface(t_interface *inter, GtkWidget *window);
void				ft_iter(GtkTreeIter *iter, GtkListStore *list,
		int ind, char *label);
t_elem				*ft_select_elem(t_interface *inter);
void				ft_switch(t_1d_button *swit,
		GtkWidget *container, char *name);
void				ft_select_elem_actif(GtkWidget *widget, gpointer data);
void				ft_set_entry_3d(t_interface *inter, t_elem *elem);
void				ft_set_entry_2d(t_interface *inter, t_elem *elem);
void				ft_set_entry_1d(t_interface *inter, t_elem *elem);
void				ft_active_switch(GtkWidget *widget, GParamSpec *pspec,
		gpointer data);
void				ft_event(t_event_entry *e, t_interface *inter);
void				ft_render(GtkWidget *widget, gpointer data);
void				ft_free_p_text(t_event_entry *e);

void				ft_init(t_interface *inter);
void				ft_init_fix(t_interface *inter);
void				ft_init_effect(t_interface *inter);
void				ft_init_elem(t_elem *elem);
void				ft_init_sinus(t_interface *inter);
void				ft_init_checker(t_interface *inter);
void				ft_init_list_e(t_interface *inter);
void				ft_init_show(t_interface *inter);
void				ft_init_show_2(t_interface *inter);
void				ft_init_3d_button(t_3d_button *button);
void				ft_init_2d_button(t_2d_button *button);
void				ft_init_1d_button(t_1d_button *button);

void				ft_create_sphere(GtkWidget *widget, gpointer data);
void				ft_create_cone(GtkWidget *widget, gpointer data);
void				ft_create_cylindre(GtkWidget *widget, gpointer data);
void				ft_create_plan(GtkWidget *widget, gpointer data);
void				ft_create_carre(GtkWidget *widget, gpointer data);
void				ft_create_torre(GtkWidget *widget, gpointer data);
void				ft_create_cercle(GtkWidget *widget, gpointer data);
void				ft_create_triangle(GtkWidget *widget, gpointer data);
void				ft_create_spot(GtkWidget *widget, gpointer data);
void				ft_create_sun(GtkWidget *widget, gpointer data);
void				ft_create_ambiant(GtkWidget *widget, gpointer data);

void				ft_3d_button(t_3d_button *button,
		GtkWidget *container, char *name);
void				ft_2d_button(t_2d_button *button,
		GtkWidget *container, char *name);
void				ft_1d_button(t_1d_button *button,
		GtkWidget *container, char *name);

void				ft_show_reflect(t_interface *inter, GtkWidget *widget);
void				ft_show_refract(t_interface *inter, GtkWidget *widget);
void				ft_show_texture_c(t_interface *inter, GtkWidget *widget);
void				ft_show_texture_n(t_interface *inter, GtkWidget *widget);
void				ft_show_checker(t_interface *inter, GtkWidget *widget);
void				ft_show_sinus(t_interface *inter, GtkWidget *widget);

void				ft_type_entry_1(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter);
void				ft_type_entry_2(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter);
void				ft_type_entry_3(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter);
void				ft_type_entry_4(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter);
void				ft_type_entry_5(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter);

void				ft_event_entry1(t_event_entry *e, t_interface *inter);
void				ft_event_entry2(t_event_entry *e, t_interface *inter);
void				ft_event_entry3(t_event_entry *e, t_interface *inter);
void				ft_event_entry4(t_event_entry *e, t_interface *inter);
void				ft_event_entry5(t_event_entry *e, t_interface *inter);

void				ft_set_data_show_1d(t_1d_button button);
void				ft_set_data_show_2d(t_2d_button button);
void				ft_set_data_show_3d(t_3d_button button);
void				ft_set_data_show_cam(t_interface *inter);
void				ft_set_data_show_sphere(t_interface *inter);
void				ft_set_data_show_cone(t_interface *inter);
void				ft_set_data_show_cylindre(t_interface *inter);
void				ft_set_data_show_plan(t_interface *inter);
void				ft_set_data_show_cercle(t_interface *inter);
void				ft_set_data_show_carre(t_interface *inter);
void				ft_set_data_show_triangle(t_interface *inter);
void				ft_set_data_show_torre(t_interface *inter);

void				ft_put_2d(t_2d elem, int fd);
void				ft_put_3d(t_3d elem, int fd);
void				ft_parse_camera(t_elem *elem, int fd);
void				ft_parse_light(t_elem *elem, int fd);
void				ft_parse_prim_3d(t_elem *elem, int fd);

#endif
