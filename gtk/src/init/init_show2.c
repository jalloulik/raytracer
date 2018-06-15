/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_show2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:10:29 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/15 16:40:23 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void	ft_init_show_2(t_interface *inter)
{
	gtk_widget_hide(inter->angle.label_x);
	gtk_widget_hide(inter->angle.x);
	gtk_widget_hide(inter->rad.label_x);
	gtk_widget_hide(inter->rad.x);
	gtk_widget_hide(inter->sepia.label_x);
	gtk_widget_hide(inter->sepia.x);
	gtk_widget_hide(inter->specular.label_x);
	gtk_widget_hide(inter->specular.x);
	gtk_widget_hide(inter->reflect.on_off.label_x);
	gtk_widget_hide(inter->reflect.on_off.x);
	gtk_widget_hide(inter->refract.on_off.label_x);
	gtk_widget_hide(inter->refract.on_off.x);
	gtk_widget_hide(inter->sinus.on_off.label_x);
	gtk_widget_hide(inter->sinus.on_off.x);
	gtk_widget_hide(inter->checker.on_off.label_x);
	gtk_widget_hide(inter->checker.on_off.x);
	gtk_widget_hide(inter->tex_c.on_off.label_x);
	gtk_widget_hide(inter->tex_c.on_off.x);
	gtk_widget_hide(inter->tex_n.on_off.label_x);
	gtk_widget_hide(inter->tex_n.on_off.x);
	gtk_widget_hide(inter->light.intensity.label_x);
	gtk_widget_hide(inter->light.intensity.x);

	gtk_widget_hide(inter->fix.color.label_x);
	gtk_widget_hide(inter->fix.color.x);
	gtk_widget_hide(inter->fix.color.label_y);
	gtk_widget_hide(inter->fix.color.y);
	gtk_widget_hide(inter->fix.color.label_z);
	gtk_widget_hide(inter->fix.color.z);

	gtk_widget_hide(inter->fix.vec.label_x);
	gtk_widget_hide(inter->fix.vec.x);
	gtk_widget_hide(inter->fix.vec.label_y);
	gtk_widget_hide(inter->fix.vec.y);
	gtk_widget_hide(inter->fix.vec.label_z);
	gtk_widget_hide(inter->fix.vec.z);

	
}