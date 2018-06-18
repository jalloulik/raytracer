/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_show2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:10:29 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/18 11:48:35 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

static void	ft_init_show_5(t_interface *inter)
{
	gtk_widget_hide(inter->fix.pos.label_x);
	gtk_widget_hide(inter->fix.pos.x);
	gtk_widget_hide(inter->fix.pos.label_y);
	gtk_widget_hide(inter->fix.pos.y);
	gtk_widget_hide(inter->fix.pos.label_z);
	gtk_widget_hide(inter->fix.pos.z);
	gtk_widget_hide(inter->fix.rot.label_x);
	gtk_widget_hide(inter->fix.rot.x);
	gtk_widget_hide(inter->fix.rot.label_y);
	gtk_widget_hide(inter->fix.rot.y);
	gtk_widget_hide(inter->fix.rot.label_z);
	gtk_widget_hide(inter->fix.rot.z);
	gtk_widget_hide(inter->fix.angle_rot.label_x);
	gtk_widget_hide(inter->fix.angle_rot.x);
	gtk_widget_hide(inter->fix.translation.label_x);
	gtk_widget_hide(inter->fix.translation.x);
	gtk_widget_hide(inter->fix.translation.label_y);
	gtk_widget_hide(inter->fix.translation.y);
	gtk_widget_hide(inter->fix.translation.label_z);
	gtk_widget_hide(inter->fix.translation.z);
}

static void	ft_init_show_4(t_interface *inter)
{
	gtk_widget_hide(inter->triang.p1.label_x);
	gtk_widget_hide(inter->triang.p1.x);
	gtk_widget_hide(inter->triang.p1.label_y);
	gtk_widget_hide(inter->triang.p1.y);
	gtk_widget_hide(inter->triang.p1.label_z);
	gtk_widget_hide(inter->triang.p1.z);
	gtk_widget_hide(inter->triang.p2.label_x);
	gtk_widget_hide(inter->triang.p2.x);
	gtk_widget_hide(inter->triang.p2.label_y);
	gtk_widget_hide(inter->triang.p2.y);
	gtk_widget_hide(inter->triang.p2.label_z);
	gtk_widget_hide(inter->triang.p2.z);
	gtk_widget_hide(inter->triang.p3.label_x);
	gtk_widget_hide(inter->triang.p3.x);
	gtk_widget_hide(inter->triang.p3.label_y);
	gtk_widget_hide(inter->triang.p3.y);
	gtk_widget_hide(inter->triang.p3.label_z);
	gtk_widget_hide(inter->triang.p3.z);
}

static void	ft_init_show_3(t_interface *inter)
{
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
	gtk_widget_hide(inter->rayon_torre.r1.label_x);
	gtk_widget_hide(inter->rayon_torre.r1.x);
	gtk_widget_hide(inter->rayon_torre.r2.label_x);
	gtk_widget_hide(inter->rayon_torre.r2.x);
}

void		ft_init_show_2(t_interface *inter)
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
	ft_init_show_3(inter);
	ft_init_show_4(inter);
	ft_init_show_5(inter);
}
