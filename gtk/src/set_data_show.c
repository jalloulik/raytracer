/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_show.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:57:19 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/15 15:22:52 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void	ft_set_data_show_cam(t_interface *inter)
{
	gtk_widget_show_now(inter->sepia.label_x);
	gtk_widget_show_now(inter->sepia.x);
}

static void	ft_set_data_show_sphere(t_interface *inter)
{
	gtk_widget_show_now(inter->rad.label_x);
	gtk_widget_show_now(inter->rad.x);
	gtk_widget_show_now(inter->specular.label_x);
	gtk_widget_show_now(inter->specular.x);
	gtk_widget_show_now(inter->reflect.on_off.label_x);
	gtk_widget_show_now(inter->reflect.on_off.x);
	gtk_widget_show_now(inter->refract.on_off.label_x);
	gtk_widget_show_now(inter->refract.on_off.x);
	gtk_widget_show_now(inter->sinus.on_off.label_x);
	gtk_widget_show_now(inter->sinus.on_off.x);
	gtk_widget_show_now(inter->checker.on_off.label_x);
	gtk_widget_show_now(inter->checker.on_off.x);
	gtk_widget_show_now(inter->tex_c.on_off.label_x);
	gtk_widget_show_now(inter->tex_c.on_off.x);
	gtk_widget_show_now(inter->tex_n.on_off.label_x);
	gtk_widget_show_now(inter->tex_n.on_off.x);
	gtk_widget_show_now(inter->fix.color.label_x);
	gtk_widget_show_now(inter->fix.color.x);
	gtk_widget_show_now(inter->fix.color.label_y);
	gtk_widget_show_now(inter->fix.color.y);
	gtk_widget_show_now(inter->fix.color.label_z);
	gtk_widget_show_now(inter->fix.color.z);
}

static void	ft_set_data_show_cone(t_interface *inter)
{
	gtk_widget_show_now(inter->angle.label_x);
	gtk_widget_show_now(inter->angle.x);
	gtk_widget_show_now(inter->specular.label_x);
	gtk_widget_show_now(inter->specular.x);
	gtk_widget_show_now(inter->reflect.on_off.label_x);
	gtk_widget_show_now(inter->reflect.on_off.x);
	gtk_widget_show_now(inter->refract.on_off.label_x);
	gtk_widget_show_now(inter->refract.on_off.x);
	gtk_widget_show_now(inter->sinus.on_off.label_x);
	gtk_widget_show_now(inter->sinus.on_off.x);
	gtk_widget_show_now(inter->checker.on_off.label_x);
	gtk_widget_show_now(inter->checker.on_off.x);
	gtk_widget_show_now(inter->tex_c.on_off.label_x);
	gtk_widget_show_now(inter->tex_c.on_off.x);
	gtk_widget_show_now(inter->tex_n.on_off.label_x);
	gtk_widget_show_now(inter->tex_n.on_off.x);
	gtk_widget_show_now(inter->fix.color.label_x);
	gtk_widget_show_now(inter->fix.color.x);
	gtk_widget_show_now(inter->fix.color.label_y);
	gtk_widget_show_now(inter->fix.color.y);
	gtk_widget_show_now(inter->fix.color.label_z);
	gtk_widget_show_now(inter->fix.color.z);
	gtk_widget_show_now(inter->fix.vec.label_x);
	gtk_widget_show_now(inter->fix.vec.x);
	gtk_widget_show_now(inter->fix.vec.label_y);
	gtk_widget_show_now(inter->fix.vec.y);
	gtk_widget_show_now(inter->fix.vec.label_z);
	gtk_widget_show_now(inter->fix.vec.z);
}

static void	ft_set_data_show_cylindre(t_interface *inter)
{
	gtk_widget_show_now(inter->rad.label_x);
	gtk_widget_show_now(inter->rad.x);
	gtk_widget_show_now(inter->specular.label_x);
	gtk_widget_show_now(inter->specular.x);
	gtk_widget_show_now(inter->reflect.on_off.label_x);
	gtk_widget_show_now(inter->reflect.on_off.x);
	gtk_widget_show_now(inter->refract.on_off.label_x);
	gtk_widget_show_now(inter->refract.on_off.x);
	gtk_widget_show_now(inter->sinus.on_off.label_x);
	gtk_widget_show_now(inter->sinus.on_off.x);
	gtk_widget_show_now(inter->checker.on_off.label_x);
	gtk_widget_show_now(inter->checker.on_off.x);
	gtk_widget_show_now(inter->tex_c.on_off.label_x);
	gtk_widget_show_now(inter->tex_c.on_off.x);
	gtk_widget_show_now(inter->tex_n.on_off.label_x);
	gtk_widget_show_now(inter->tex_n.on_off.x);
	gtk_widget_show_now(inter->fix.color.label_x);
	gtk_widget_show_now(inter->fix.color.x);
	gtk_widget_show_now(inter->fix.color.label_y);
	gtk_widget_show_now(inter->fix.color.y);
	gtk_widget_show_now(inter->fix.color.label_z);
	gtk_widget_show_now(inter->fix.color.z);
	gtk_widget_show_now(inter->fix.vec.label_x);
	gtk_widget_show_now(inter->fix.vec.x);
	gtk_widget_show_now(inter->fix.vec.label_y);
	gtk_widget_show_now(inter->fix.vec.y);
	gtk_widget_show_now(inter->fix.vec.label_z);
	gtk_widget_show_now(inter->fix.vec.z);
}

static void	ft_set_data_show_plan(t_interface *inter)
{
	gtk_widget_show_now(inter->specular.label_x);
	gtk_widget_show_now(inter->specular.x);
	gtk_widget_show_now(inter->reflect.on_off.label_x);
	gtk_widget_show_now(inter->reflect.on_off.x);
	gtk_widget_show_now(inter->refract.on_off.label_x);
	gtk_widget_show_now(inter->refract.on_off.x);
	gtk_widget_show_now(inter->sinus.on_off.label_x);
	gtk_widget_show_now(inter->sinus.on_off.x);
	gtk_widget_show_now(inter->checker.on_off.label_x);
	gtk_widget_show_now(inter->checker.on_off.x);
	gtk_widget_show_now(inter->tex_c.on_off.label_x);
	gtk_widget_show_now(inter->tex_c.on_off.x);
	gtk_widget_show_now(inter->tex_n.on_off.label_x);
	gtk_widget_show_now(inter->tex_n.on_off.x);
	gtk_widget_show_now(inter->fix.color.label_x);
	gtk_widget_show_now(inter->fix.color.x);
	gtk_widget_show_now(inter->fix.color.label_y);
	gtk_widget_show_now(inter->fix.color.y);
	gtk_widget_show_now(inter->fix.color.label_z);
	gtk_widget_show_now(inter->fix.color.z);
	gtk_widget_show_now(inter->fix.vec.label_x);
	gtk_widget_show_now(inter->fix.vec.x);
	gtk_widget_show_now(inter->fix.vec.label_y);
	gtk_widget_show_now(inter->fix.vec.y);
	gtk_widget_show_now(inter->fix.vec.label_z);
	gtk_widget_show_now(inter->fix.vec.z);
}

static void	ft_set_data_show_cercle(t_interface *inter)
{
	gtk_widget_show_now(inter->rad.label_x);
	gtk_widget_show_now(inter->rad.x);
	gtk_widget_show_now(inter->specular.label_x);
	gtk_widget_show_now(inter->specular.x);
	gtk_widget_show_now(inter->reflect.on_off.label_x);
	gtk_widget_show_now(inter->reflect.on_off.x);
	gtk_widget_show_now(inter->refract.on_off.label_x);
	gtk_widget_show_now(inter->refract.on_off.x);
	gtk_widget_show_now(inter->sinus.on_off.label_x);
	gtk_widget_show_now(inter->sinus.on_off.x);
	gtk_widget_show_now(inter->checker.on_off.label_x);
	gtk_widget_show_now(inter->checker.on_off.x);
	gtk_widget_show_now(inter->tex_c.on_off.label_x);
	gtk_widget_show_now(inter->tex_c.on_off.x);
	gtk_widget_show_now(inter->tex_n.on_off.label_x);
	gtk_widget_show_now(inter->tex_n.on_off.x);
	gtk_widget_show_now(inter->fix.color.label_x);
	gtk_widget_show_now(inter->fix.color.x);
	gtk_widget_show_now(inter->fix.color.label_y);
	gtk_widget_show_now(inter->fix.color.y);
	gtk_widget_show_now(inter->fix.color.label_z);
	gtk_widget_show_now(inter->fix.color.z);
}

static void	ft_set_data_show_spot(t_interface *inter)
{
	gtk_widget_show_now(inter->fix.color.label_x);
	gtk_widget_show_now(inter->fix.color.x);
	gtk_widget_show_now(inter->fix.color.label_y);
	gtk_widget_show_now(inter->fix.color.y);
	gtk_widget_show_now(inter->fix.color.label_z);
	gtk_widget_show_now(inter->fix.color.z);
	gtk_widget_show_now(inter->light.intensity.label_x);
	gtk_widget_show_now(inter->light.intensity.x);
}

static void	ft_set_data_show_sun(t_interface *inter)
{
	gtk_widget_show_now(inter->fix.color.label_x);
	gtk_widget_show_now(inter->fix.color.x);
	gtk_widget_show_now(inter->fix.color.label_y);
	gtk_widget_show_now(inter->fix.color.y);
	gtk_widget_show_now(inter->fix.color.label_z);
	gtk_widget_show_now(inter->fix.color.z);
	gtk_widget_show_now(inter->light.intensity.label_x);
	gtk_widget_show_now(inter->light.intensity.x);
}

static void	ft_set_data_show_ambiant(t_interface *inter)
{
	gtk_widget_show_now(inter->fix.color.label_x);
	gtk_widget_show_now(inter->fix.color.x);
	gtk_widget_show_now(inter->fix.color.label_y);
	gtk_widget_show_now(inter->fix.color.y);
	gtk_widget_show_now(inter->fix.color.label_z);
	gtk_widget_show_now(inter->fix.color.z);
	gtk_widget_show_now(inter->light.intensity.label_x);
	gtk_widget_show_now(inter->light.intensity.x);
}

void	ft_set_data_show(t_interface *inter, t_elem *elem)
{
	ft_init_show(inter);
	if (elem->type == CAM)
		ft_set_data_show_cam(inter);
	if (elem->type == SPHERE)
		ft_set_data_show_sphere(inter);
	if (elem->type == CONE)
		ft_set_data_show_cone(inter);
	if (elem->type == PLAN)
		ft_set_data_show_plan(inter);
	if (elem->type == CYLINDRE)
		ft_set_data_show_cylindre(inter);
	if (elem->type == CERCLE)
		ft_set_data_show_cercle(inter);
	/*if (elem->type == CARRE)
		ft_set_data_show_carre(inter);
	if (elem->type == TRIANGLE)
		ft_set_data_show_triangle(inter);
	if (elem->type == TORRE)
		ft_set_data_show_torre(inter);*/
	if (elem->type == SPOT)
		ft_set_data_show_spot(inter);
	if (elem->type == SUN)
		ft_set_data_show_sun(inter);
	if (elem->type == AMBIANT)
		ft_set_data_show_ambiant(inter);
}