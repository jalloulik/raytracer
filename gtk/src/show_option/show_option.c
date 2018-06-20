/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:39:18 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/18 12:00:33 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void			ft_show_reflect(t_interface *inter, GtkWidget *widget)
{
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 0)
	{
		gtk_widget_hide(inter->reflect.pourcent.label_x);
		gtk_widget_hide(inter->reflect.pourcent.x);
	}
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 1)
	{
		gtk_widget_show_now(inter->reflect.pourcent.label_x);
		gtk_widget_show_now(inter->reflect.pourcent.x);
	}
}

void			ft_show_refract(t_interface *inter, GtkWidget *widget)
{
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 0)
	{
		gtk_widget_hide(inter->refract.pourcent.label_x);
		gtk_widget_hide(inter->refract.pourcent.x);
		gtk_widget_hide(inter->refract.material.label_x);
		gtk_widget_hide(inter->refract.material.x);
	}
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 1)
	{
		gtk_widget_show_now(inter->refract.pourcent.label_x);
		gtk_widget_show_now(inter->refract.pourcent.x);
		gtk_widget_show_now(inter->refract.material.label_x);
		gtk_widget_show_now(inter->refract.material.x);
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
