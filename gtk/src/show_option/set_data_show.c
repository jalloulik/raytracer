/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_show.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:57:19 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/24 17:20:47 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

static void	ft_set_data_show_light(t_interface *inter, t_elem *elem)
{
	if (elem->type == SPOT)
	{
		ft_set_data_show_3d(inter->fix.pos);
		ft_set_data_show_1d(inter->light.intensity);
	}
	if (elem->type == SUN)
	{
		ft_set_data_show_3d(inter->fix.pos);
		ft_set_data_show_1d(inter->light.intensity);
	}
	if (elem->type == AMBIANT)
		ft_set_data_show_1d(inter->light.intensity);
}

static void	ft_show_switch(t_interface *inter, t_elem *elem)
{
	ft_show_switch_reflect(inter, elem);
	ft_show_switch_refract(inter, elem);
	ft_show_switch_checker(inter, elem);
	ft_show_switch_sinus(inter, elem);
	ft_show_switch_texture_c(inter, elem);
	ft_show_switch_texture_n(inter, elem);
	ft_show_cut(inter, elem);
}

void		ft_set_data_show(t_interface *inter, t_elem *elem)
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
	if (elem->type == CARRE)
		ft_set_data_show_carre(inter);
	if (elem->type == TRIANGLE)
		ft_set_data_show_triangle(inter);
	if (elem->type == TORRE)
		ft_set_data_show_torre(inter);
	ft_set_data_show_light(inter, elem);
	ft_show_switch(inter, elem);
}
