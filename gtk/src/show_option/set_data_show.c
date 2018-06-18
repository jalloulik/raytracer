/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_show.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:57:19 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/18 13:33:18 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

static void	ft_set_data_show_spot(t_interface *inter)
{
	ft_set_data_show_3d(inter->fix.pos);
	ft_set_data_show_3d(inter->fix.color);
	ft_set_data_show_1d(inter->light.intensity);
}

static void	ft_set_data_show_sun(t_interface *inter)
{
	ft_set_data_show_3d(inter->fix.pos);
	ft_set_data_show_3d(inter->fix.color);
	ft_set_data_show_1d(inter->light.intensity);
}

static void	ft_set_data_show_ambiant(t_interface *inter)
{
	ft_set_data_show_1d(inter->light.intensity);
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
	if (elem->type == CARRE)
		ft_set_data_show_carre(inter);
	if (elem->type == TRIANGLE)
		ft_set_data_show_triangle(inter);
	if (elem->type == TORRE)
		ft_set_data_show_torre(inter);
	if (elem->type == SPOT)
		ft_set_data_show_spot(inter);
	if (elem->type == SUN)
		ft_set_data_show_sun(inter);
	if (elem->type == AMBIANT)
		ft_set_data_show_ambiant(inter);
}