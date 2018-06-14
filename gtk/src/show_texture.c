/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:20:24 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 13:26:19 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void		ft_show_texture_c_move(t_interface *inter, GtkWidget *widget)
{
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 0)
	{
		gtk_widget_hide(inter->tex_c.name.label_x);
		gtk_widget_hide(inter->tex_c.name.x);
		gtk_widget_hide(inter->tex_c.move.label_x);
		gtk_widget_hide(inter->tex_c.move.x);
		gtk_widget_hide(inter->tex_c.move.label_y);
		gtk_widget_hide(inter->tex_c.move.y);
	}
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 1)
	{
		gtk_widget_show_now(inter->tex_c.name.label_x);
		gtk_widget_show_now(inter->tex_c.name.x);
		gtk_widget_show_now(inter->tex_c.move.label_x);
		gtk_widget_show_now(inter->tex_c.move.x);
		gtk_widget_show_now(inter->tex_c.move.label_y);
		gtk_widget_show_now(inter->tex_c.move.y);
	}
}

void			ft_show_texture_c(t_interface *inter, GtkWidget *widget)
{
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 0)
	{
		gtk_widget_hide(inter->tex_c.scale.label_x);
		gtk_widget_hide(inter->tex_c.scale.x);
		gtk_widget_hide(inter->tex_c.scale.label_y);
		gtk_widget_hide(inter->tex_c.scale.y);
	}
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 1)
	{
		gtk_widget_show_now(inter->tex_c.scale.label_x);
		gtk_widget_show_now(inter->tex_c.scale.x);
		gtk_widget_show_now(inter->tex_c.scale.label_y);
		gtk_widget_show_now(inter->tex_c.scale.y);
	}
	ft_show_texture_c_move(inter, widget);
}

static void		ft_show_texture_n_move(t_interface *inter, GtkWidget *widget)
{
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 0)
	{
		gtk_widget_hide(inter->tex_n.name.label_x);
		gtk_widget_hide(inter->tex_n.name.x);
		gtk_widget_hide(inter->tex_n.move.label_x);
		gtk_widget_hide(inter->tex_n.move.x);
		gtk_widget_hide(inter->tex_n.move.label_y);
		gtk_widget_hide(inter->tex_n.move.y);
	}
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 1)
	{
		gtk_widget_show_now(inter->tex_n.name.label_x);
		gtk_widget_show_now(inter->tex_n.name.x);
		gtk_widget_show_now(inter->tex_n.move.label_x);
		gtk_widget_show_now(inter->tex_n.move.x);
		gtk_widget_show_now(inter->tex_n.move.label_y);
		gtk_widget_show_now(inter->tex_n.move.y);
	}
}

void			ft_show_texture_n(t_interface *inter, GtkWidget *widget)
{
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 0)
	{
		gtk_widget_hide(inter->tex_n.scale.label_x);
		gtk_widget_hide(inter->tex_n.scale.x);
		gtk_widget_hide(inter->tex_n.scale.label_y);
		gtk_widget_hide(inter->tex_n.scale.y);
	}
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 1)
	{
		gtk_widget_show_now(inter->tex_n.scale.label_x);
		gtk_widget_show_now(inter->tex_n.scale.x);
		gtk_widget_show_now(inter->tex_n.scale.label_y);
		gtk_widget_show_now(inter->tex_n.scale.y);
	}
	ft_show_texture_n_move(inter, widget);
}
