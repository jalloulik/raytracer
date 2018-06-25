/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_sinus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:17:47 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/18 12:00:52 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

static void		ft_show_sin_x(t_interface *inter, GtkWidget *widget)
{
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 0)
	{
		gtk_widget_hide(inter->sinus.sin_x.label_x);
		gtk_widget_hide(inter->sinus.sin_x.x);
		gtk_widget_hide(inter->sinus.sin_x.label_y);
		gtk_widget_hide(inter->sinus.sin_x.y);
	}
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 1)
	{
		gtk_widget_show_now(inter->sinus.sin_x.label_x);
		gtk_widget_show_now(inter->sinus.sin_x.x);
		gtk_widget_show_now(inter->sinus.sin_x.label_y);
		gtk_widget_show_now(inter->sinus.sin_x.y);
	}
}

void			ft_show_sinus(t_interface *inter, GtkWidget *widget)
{
	if (gtk_switch_get_state(GTK_SWITCH(widget)) == 0)
	{
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
		gtk_widget_show_now(inter->sinus.sin_y.label_x);
		gtk_widget_show_now(inter->sinus.sin_y.x);
		gtk_widget_show_now(inter->sinus.sin_y.label_y);
		gtk_widget_show_now(inter->sinus.sin_y.y);
		gtk_widget_show_now(inter->sinus.sin_z.label_x);
		gtk_widget_show_now(inter->sinus.sin_z.x);
		gtk_widget_show_now(inter->sinus.sin_z.label_y);
		gtk_widget_show_now(inter->sinus.sin_z.y);
	}
	ft_show_sin_x(inter, widget);
}
