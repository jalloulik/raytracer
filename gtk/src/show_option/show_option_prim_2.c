/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_option_prim_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:03:10 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 18:02:58 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void	ft_set_data_show_cercle(t_interface *inter)
{
	ft_set_data_show_3d(inter->fix.pos);
	ft_set_data_show_3d(inter->fix.rot);
	ft_set_data_show_1d(inter->fix.angle_rot);
	ft_set_data_show_3d(inter->fix.translation);
	ft_set_data_show_3d(inter->fix.color);
	ft_set_data_show_3d(inter->fix.vec);
	ft_set_data_show_1d(inter->rad);
	ft_set_data_show_1d(inter->reflect.on_off);
	ft_set_data_show_1d(inter->refract.on_off);
	ft_set_data_show_1d(inter->sinus.on_off);
	ft_set_data_show_1d(inter->checker.on_off);
	ft_set_data_show_1d(inter->tex_c.on_off);
	ft_set_data_show_1d(inter->tex_n.on_off);
}

void	ft_set_data_show_triangle(t_interface *inter)
{
	ft_set_data_show_3d(inter->triang.p1);
	ft_set_data_show_3d(inter->triang.p2);
	ft_set_data_show_3d(inter->triang.p3);
	ft_set_data_show_3d(inter->fix.rot);
	ft_set_data_show_1d(inter->fix.angle_rot);
	ft_set_data_show_3d(inter->fix.translation);
	ft_set_data_show_3d(inter->fix.color);
	ft_set_data_show_1d(inter->reflect.on_off);
	ft_set_data_show_1d(inter->refract.on_off);
	ft_set_data_show_1d(inter->sinus.on_off);
	ft_set_data_show_1d(inter->checker.on_off);
	ft_set_data_show_1d(inter->tex_c.on_off);
	ft_set_data_show_1d(inter->tex_n.on_off);
}

void	ft_set_data_show_torre(t_interface *inter)
{
	ft_set_data_show_3d(inter->fix.pos);
	ft_set_data_show_3d(inter->fix.color);
	ft_set_data_show_3d(inter->fix.vec);
	ft_set_data_show_3d(inter->fix.rot);
	ft_set_data_show_1d(inter->fix.angle_rot);
	ft_set_data_show_3d(inter->fix.translation);
	ft_set_data_show_1d(inter->reflect.on_off);
	ft_set_data_show_1d(inter->refract.on_off);
	ft_set_data_show_1d(inter->sinus.on_off);
	ft_set_data_show_1d(inter->checker.on_off);
	ft_set_data_show_1d(inter->tex_c.on_off);
	ft_set_data_show_1d(inter->tex_n.on_off);
	ft_set_data_show_1d(inter->rayon_torre.r1);
	ft_set_data_show_1d(inter->rayon_torre.r2);
}

void	ft_set_data_show_carre(t_interface *inter)
{
	ft_set_data_show_3d(inter->fix.pos);
	ft_set_data_show_3d(inter->fix.color);
	ft_set_data_show_3d(inter->fix.rot);
	ft_set_data_show_1d(inter->fix.angle_rot);
	ft_set_data_show_3d(inter->fix.translation);
	ft_set_data_show_3d(inter->fix.vec);
	ft_set_data_show_1d(inter->reflect.on_off);
	ft_set_data_show_1d(inter->refract.on_off);
	ft_set_data_show_1d(inter->sinus.on_off);
	ft_set_data_show_1d(inter->checker.on_off);
	ft_set_data_show_1d(inter->tex_c.on_off);
	ft_set_data_show_1d(inter->tex_n.on_off);
	ft_set_data_show_2d(inter->size);
}
