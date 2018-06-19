/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 10:20:36 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/19 14:28:21 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void				ft_e(t_event_entry *e, t_interface *inter)
{
	e->inter = inter;
	e->value = NULL;
	e->value_char = NULL;
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
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
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
	ft_event(&e, &inter);
	g_signal_connect(G_OBJECT(window), "delete-event",
		G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all(window);
	ft_init_show(&inter);
	gtk_main();
	return (0);
}
