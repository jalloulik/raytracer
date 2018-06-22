/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_option_prim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:01:59 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/22 18:08:25 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void	ft_set_data_show_cam(t_interface *inter)
{
	ft_set_data_show_3d(inter->fix.pos);
	ft_set_data_show_3d(inter->fix.rot);
	ft_set_data_show_1d(inter->fix.angle_rot);
	ft_set_data_show_3d(inter->fix.translation);
	ft_set_data_show_1d(inter->sepia);
}

void	ft_set_data_show_sphere(t_interface *inter)
{
	ft_set_data_show_3d(inter->fix.pos);
	ft_set_data_show_3d(inter->fix.rot);
	ft_set_data_show_1d(inter->fix.angle_rot);
	ft_set_data_show_3d(inter->fix.translation);
	ft_set_data_show_1d(inter->rad);
	ft_set_data_show_1d(inter->specular);
	ft_set_data_show_1d(inter->reflect.on_off);
	ft_set_data_show_1d(inter->refract.on_off);
	ft_set_data_show_1d(inter->sinus.on_off);
	ft_set_data_show_1d(inter->checker.on_off);
	ft_set_data_show_1d(inter->tex_c.on_off);
	ft_set_data_show_1d(inter->tex_n.on_off);
	ft_set_data_show_3d(inter->fix.color);
}

void	ft_set_data_show_cone(t_interface *inter)
{
	ft_set_data_show_3d(inter->fix.pos);
	ft_set_data_show_3d(inter->fix.rot);
	ft_set_data_show_1d(inter->fix.angle_rot);
	ft_set_data_show_3d(inter->fix.translation);
	ft_set_data_show_1d(inter->angle);
	ft_set_data_show_1d(inter->specular);
	ft_set_data_show_1d(inter->reflect.on_off);
	ft_set_data_show_1d(inter->refract.on_off);
	ft_set_data_show_1d(inter->sinus.on_off);
	ft_set_data_show_1d(inter->checker.on_off);
	ft_set_data_show_1d(inter->tex_c.on_off);
	ft_set_data_show_1d(inter->tex_n.on_off);
	ft_set_data_show_3d(inter->fix.color);
	ft_set_data_show_3d(inter->fix.vec);
}

void	ft_set_data_show_cylindre(t_interface *inter)
{
	ft_set_data_show_3d(inter->fix.pos);
	ft_set_data_show_3d(inter->fix.rot);
	ft_set_data_show_1d(inter->fix.angle_rot);
	ft_set_data_show_3d(inter->fix.translation);
	ft_set_data_show_1d(inter->rad);
	ft_set_data_show_1d(inter->specular);
	ft_set_data_show_1d(inter->reflect.on_off);
	ft_set_data_show_1d(inter->refract.on_off);
	ft_set_data_show_1d(inter->sinus.on_off);
	ft_set_data_show_1d(inter->checker.on_off);
	ft_set_data_show_1d(inter->tex_c.on_off);
	ft_set_data_show_1d(inter->tex_n.on_off);
	ft_set_data_show_3d(inter->fix.color);
	ft_set_data_show_3d(inter->fix.vec);
}

void	ft_set_data_show_plan(t_interface *inter)
{
	ft_set_data_show_3d(inter->fix.pos);
	ft_set_data_show_3d(inter->fix.rot);
	ft_set_data_show_1d(inter->fix.angle_rot);
	ft_set_data_show_3d(inter->fix.translation);
	ft_set_data_show_1d(inter->specular);
	ft_set_data_show_1d(inter->reflect.on_off);
	ft_set_data_show_1d(inter->refract.on_off);
	ft_set_data_show_1d(inter->sinus.on_off);
	ft_set_data_show_1d(inter->checker.on_off);
	ft_set_data_show_1d(inter->tex_c.on_off);
	ft_set_data_show_1d(inter->tex_n.on_off);
	ft_set_data_show_3d(inter->fix.color);
	ft_set_data_show_3d(inter->fix.vec);
}
