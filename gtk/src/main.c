/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 10:20:36 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 07:56:17 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void			ft_e(t_event_entry *e, t_interface *inter)
{
	e->inter = inter;
	e->value = NULL;
	e->index1 = 0;
	e->index2 = 0;
	e->p_text1 = NULL;
	e->p_text2 = NULL;
}

GtkWidget			*ft_window(char *title)
{
	GtkWidget		*window;

	window = NULL;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(window), title);
	gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
	//gtk_window_set_resizable (GTK_WINDOW(window), FALSE);
	return (window);
}

int					main(int argc, char **argv)
{
	GtkWidget		*window;
	t_interface		inter;
	t_event_entry	e;

	window = NULL;
	ft_init(&inter);
	gtk_init(&argc, &argv);
	window = ft_window("ui");
	ft_interface(&inter, window);
	ft_init_list_e(&inter);
	ft_e(&e, &inter);
	g_signal_connect(G_OBJECT(inter.prim.sphere), "clicked", G_CALLBACK(ft_create_sphere), &inter);
	g_signal_connect(G_OBJECT(inter.prim.cone), "clicked", G_CALLBACK(ft_create_cone), &inter);
	g_signal_connect(G_OBJECT(inter.prim.cylindre), "clicked", G_CALLBACK(ft_create_cylindre), &inter);
	g_signal_connect(G_OBJECT(inter.prim.plan), "clicked", G_CALLBACK(ft_create_plan), &inter);
	g_signal_connect(G_OBJECT(inter.list.button), "changed", G_CALLBACK(ft_select_elem_actif), &e);
	g_signal_connect(G_OBJECT(inter.fix.pos.x), "changed", G_CALLBACK(ft_entry_value), &e);
	g_signal_connect(G_OBJECT(inter.fix.pos.y), "changed", G_CALLBACK(ft_entry_value), &e);
	g_signal_connect(G_OBJECT(inter.fix.pos.z), "changed", G_CALLBACK(ft_entry_value), &e);
	g_signal_connect(G_OBJECT(inter.fix.translation.x), "changed", G_CALLBACK(ft_entry_value), &e);
	g_signal_connect(G_OBJECT(inter.fix.translation.y), "changed", G_CALLBACK(ft_entry_value), &e);
	g_signal_connect(G_OBJECT(inter.fix.translation.z), "changed", G_CALLBACK(ft_entry_value), &e);
	g_signal_connect(G_OBJECT(inter.fix.vec.x), "changed", G_CALLBACK(ft_entry_value), &e);
	g_signal_connect(G_OBJECT(inter.fix.vec.y), "changed", G_CALLBACK(ft_entry_value), &e);
	g_signal_connect(G_OBJECT(inter.fix.vec.z), "changed", G_CALLBACK(ft_entry_value), &e);
	g_signal_connect(G_OBJECT(inter.fix.rot.x), "changed", G_CALLBACK(ft_entry_value), &e);
	g_signal_connect(G_OBJECT(inter.fix.rot.y), "changed", G_CALLBACK(ft_entry_value), &e);
	g_signal_connect(G_OBJECT(inter.fix.angle_rot.x), "changed", G_CALLBACK(ft_entry_value), &e);
	g_signal_connect(G_OBJECT(inter.fix.rot.z), "changed", G_CALLBACK(ft_entry_value), &e);
	g_signal_connect(G_OBJECT(inter.specular.x), "notify::active", G_CALLBACK(ft_active_switch), &e);
	g_signal_connect(G_OBJECT(inter.reflect.on_off.x), "notify::active", G_CALLBACK(ft_active_switch), &e);
	g_signal_connect(G_OBJECT(inter.refract.on_off.x), "notify::active", G_CALLBACK(ft_active_switch), &e);
	g_signal_connect(G_OBJECT(inter.tex_c.on_off.x), "notify::active", G_CALLBACK(ft_active_switch), &e);
	g_signal_connect(G_OBJECT(inter.tex_n.on_off.x), "notify::active", G_CALLBACK(ft_active_switch), &e);
	g_signal_connect(G_OBJECT(inter.sinus.on_off.x), "notify::active", G_CALLBACK(ft_active_switch), &e);
	g_signal_connect(G_OBJECT(inter.checker.on_off.x), "notify::active", G_CALLBACK(ft_active_switch), &e);
	g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all(window);
	ft_init_show(&inter);
	gtk_main();
	return (0);
}
