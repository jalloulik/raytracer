/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:39:18 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/12 15:32:37 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void			ft_show_reflect(t_interface *inter, GtkWidget *widget)
{
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 0)
	{
		gtk_widget_hide(inter->reflect.value.label_x);
		gtk_widget_hide(inter->reflect.value.x);
	}
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 1)
	{
		gtk_widget_show_now(inter->reflect.value.label_x);
		gtk_widget_show_now(inter->reflect.value.x);
	}
}

void			ft_show_refract(t_interface *inter, GtkWidget *widget)
{
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 0)
	{
		gtk_widget_hide(inter->refract.value.label_x);
		gtk_widget_hide(inter->refract.value.x);
		gtk_widget_hide(inter->refract.material.label_x);
		gtk_widget_hide(inter->refract.material.x);
	}
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 1)
	{
		gtk_widget_show_now(inter->refract.value.label_x);
		gtk_widget_show_now(inter->refract.value.x);
		gtk_widget_show_now(inter->refract.material.label_x);
		gtk_widget_show_now(inter->refract.material.x);
	}
}

void			ft_show_texture_c(t_interface *inter, GtkWidget *widget)
{
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 0)
	{
		gtk_widget_hide(inter->tex_c.name.label_x);
		gtk_widget_hide(inter->tex_c.name.x);
		gtk_widget_hide(inter->tex_c.move.label_x);
		gtk_widget_hide(inter->tex_c.move.x);
		gtk_widget_hide(inter->tex_c.move.label_y);
		gtk_widget_hide(inter->tex_c.move.y);
		gtk_widget_hide(inter->tex_c.scale.label_x);
		gtk_widget_hide(inter->tex_c.scale.x);
		gtk_widget_hide(inter->tex_c.scale.label_y);
		gtk_widget_hide(inter->tex_c.scale.y);
	}
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 1)
	{
		gtk_widget_show_now(inter->tex_c.name.label_x);
		gtk_widget_show_now(inter->tex_c.name.x);
		gtk_widget_show_now(inter->tex_c.move.label_x);
		gtk_widget_show_now(inter->tex_c.move.x);
		gtk_widget_show_now(inter->tex_c.move.label_y);
		gtk_widget_show_now(inter->tex_c.move.y);
		gtk_widget_show_now(inter->tex_c.scale.label_x);
		gtk_widget_show_now(inter->tex_c.scale.x);
		gtk_widget_show_now(inter->tex_c.scale.label_y);
		gtk_widget_show_now(inter->tex_c.scale.y);
	}
}

void			ft_show_texture_n(t_interface *inter, GtkWidget *widget)
{
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 0)
	{
		gtk_widget_hide(inter->tex_n.name.label_x);
		gtk_widget_hide(inter->tex_n.name.x);
		gtk_widget_hide(inter->tex_n.move.label_x);
		gtk_widget_hide(inter->tex_n.move.x);
		gtk_widget_hide(inter->tex_n.move.label_y);
		gtk_widget_hide(inter->tex_n.move.y);
		gtk_widget_hide(inter->tex_n.scale.label_x);
		gtk_widget_hide(inter->tex_n.scale.x);
		gtk_widget_hide(inter->tex_n.scale.label_y);
		gtk_widget_hide(inter->tex_n.scale.y);
	}
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 1)
	{
		gtk_widget_show_now(inter->tex_n.name.label_x);
		gtk_widget_show_now(inter->tex_n.name.x);
		gtk_widget_show_now(inter->tex_n.move.label_x);
		gtk_widget_show_now(inter->tex_n.move.x);
		gtk_widget_show_now(inter->tex_n.move.label_y);
		gtk_widget_show_now(inter->tex_n.move.y);
		gtk_widget_show_now(inter->tex_n.scale.label_x);
		gtk_widget_show_now(inter->tex_n.scale.x);
		gtk_widget_show_now(inter->tex_n.scale.label_y);
		gtk_widget_show_now(inter->tex_n.scale.y);
	}
}

void			ft_show_sinus(t_interface *inter, GtkWidget *widget)
{
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 0)
	{
		gtk_widget_hide(inter->sinus.sin_x.label_x);
		gtk_widget_hide(inter->sinus.sin_x.x);
		gtk_widget_hide(inter->sinus.sin_x.label_y);
		gtk_widget_hide(inter->sinus.sin_x.y);
		gtk_widget_hide(inter->sinus.sin_y.label_x);
		gtk_widget_hide(inter->sinus.sin_y.x);
		gtk_widget_hide(inter->sinus.sin_y.label_y);
		gtk_widget_hide(inter->sinus.sin_y.y);
		gtk_widget_hide(inter->sinus.sin_z.label_x);
		gtk_widget_hide(inter->sinus.sin_z.x);
		gtk_widget_hide(inter->sinus.sin_z.label_y);
		gtk_widget_hide(inter->sinus.sin_z.y);
	}
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 1)
	{
		gtk_widget_show_now(inter->sinus.sin_x.label_x);
		gtk_widget_show_now(inter->sinus.sin_x.x);
		gtk_widget_show_now(inter->sinus.sin_x.label_y);
		gtk_widget_show_now(inter->sinus.sin_x.y);
		gtk_widget_show_now(inter->sinus.sin_y.label_x);
		gtk_widget_show_now(inter->sinus.sin_y.x);
		gtk_widget_show_now(inter->sinus.sin_y.label_y);
		gtk_widget_show_now(inter->sinus.sin_y.y);
		gtk_widget_show_now(inter->sinus.sin_z.label_x);
		gtk_widget_show_now(inter->sinus.sin_z.x);
		gtk_widget_show_now(inter->sinus.sin_z.label_y);
		gtk_widget_show_now(inter->sinus.sin_z.y);
	}
}

void			ft_show_checker(t_interface *inter, GtkWidget *widget)
{
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 0)
	{
		gtk_widget_hide(inter->checker.move.label_x);
		gtk_widget_hide(inter->checker.move.x);
		gtk_widget_hide(inter->checker.move.label_y);
		gtk_widget_hide(inter->checker.move.y);
		gtk_widget_hide(inter->checker.scale.label_x);
		gtk_widget_hide(inter->checker.scale.x);
		gtk_widget_hide(inter->checker.scale.label_y);
		gtk_widget_hide(inter->checker.scale.y);
	}
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 1)
	{
		gtk_widget_show_now(inter->checker.move.label_x);
		gtk_widget_show_now(inter->checker.move.x);
		gtk_widget_show_now(inter->checker.move.label_y);
		gtk_widget_show_now(inter->checker.move.y);
		gtk_widget_show_now(inter->checker.scale.label_x);
		gtk_widget_show_now(inter->checker.scale.x);
		gtk_widget_show_now(inter->checker.scale.label_y);
		gtk_widget_show_now(inter->checker.scale.y);
	}
}