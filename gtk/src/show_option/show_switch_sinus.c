/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_switch_sinus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:58:25 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/21 17:19:45 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

static void		ft_show_switch_sin_x(t_interface *inter, t_elem *elem)
{
	if (elem->sinus.on_off == 0)
	{
		gtk_widget_hide(inter->sinus.sin_x.label_x);
		gtk_widget_hide(inter->sinus.sin_x.x);
		gtk_widget_hide(inter->sinus.sin_x.label_y);
		gtk_widget_hide(inter->sinus.sin_x.y);
	}
	if (elem->sinus.on_off == 1)
	{
		gtk_widget_show_now(inter->sinus.sin_x.label_x);
		gtk_widget_show_now(inter->sinus.sin_x.x);
		gtk_widget_show_now(inter->sinus.sin_x.label_y);
		gtk_widget_show_now(inter->sinus.sin_x.y);
	}
}

void			ft_show_switch_sinus(t_interface *inter, t_elem *elem)
{
	if (elem->sinus.on_off == 0)
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
	if (elem->sinus.on_off == 1)
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
	ft_show_switch_sin_x(inter, elem);
}
