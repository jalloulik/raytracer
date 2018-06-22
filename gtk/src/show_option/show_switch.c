/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_switch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:52:12 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/21 17:20:23 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void		ft_show_switch_reflect(t_interface *inter, t_elem *elem)
{
	if (elem->reflect.on_off == 0)
	{
		gtk_widget_hide(inter->reflect.pourcent.label_x);
		gtk_widget_hide(inter->reflect.pourcent.x);
	}
	if (elem->reflect.on_off == 1)
	{
		gtk_widget_show_now(inter->reflect.pourcent.label_x);
		gtk_widget_show_now(inter->reflect.pourcent.x);
	}
}

void		ft_show_switch_checker(t_interface *inter, t_elem *elem)
{
	if (elem->checker.on_off == 0)
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
	if (elem->checker.on_off == 1)
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

void		ft_show_switch_refract(t_interface *inter, t_elem *elem)
{
	if (elem->refract.on_off == 0)
	{
		gtk_widget_hide(inter->refract.pourcent.label_x);
		gtk_widget_hide(inter->refract.pourcent.x);
		gtk_widget_hide(inter->refract.material.label_x);
		gtk_widget_hide(inter->refract.material.x);
	}
	if (elem->refract.on_off == 1)
	{
		gtk_widget_show_now(inter->refract.pourcent.label_x);
		gtk_widget_show_now(inter->refract.pourcent.x);
		gtk_widget_show_now(inter->refract.material.label_x);
		gtk_widget_show_now(inter->refract.material.x);
	}
}
