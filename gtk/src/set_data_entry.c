/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:12:31 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/19 14:12:56 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void				ft_set_entry_3d(t_interface *inter, t_elem *elem)
{
	ft_set_3d_entry(&inter->fix.pos, elem->pos);
	ft_set_3d_entry(&inter->fix.translation, elem->translation);
	ft_set_3d_entry(&inter->fix.vec, elem->vec);
	ft_set_3d_entry(&inter->fix.rot, elem->rot);
	ft_set_3d_entry(&inter->fix.color, elem->color);
	ft_set_3d_entry(&inter->triang.p1, elem->triang.p1);
	ft_set_3d_entry(&inter->triang.p2, elem->triang.p2);
	ft_set_3d_entry(&inter->triang.p3, elem->triang.p3);
}

void				ft_set_entry_2d(t_interface *inter, t_elem *elem)
{
	ft_set_2d_entry(&inter->tex_c.move, elem->tex_c.move);
	ft_set_2d_entry(&inter->tex_c.scale, elem->tex_c.scale);
	ft_set_2d_entry(&inter->tex_n.move, elem->tex_n.move);
	ft_set_2d_entry(&inter->tex_n.scale, elem->tex_n.scale);
	ft_set_2d_entry(&inter->checker.move, elem->checker.move);
	ft_set_2d_entry(&inter->checker.scale, elem->checker.scale);
	ft_set_2d_entry(&inter->sinus.sin_x, elem->sinus.sin_x);
	ft_set_2d_entry(&inter->sinus.sin_y, elem->sinus.sin_y);
	ft_set_2d_entry(&inter->sinus.sin_z, elem->sinus.sin_z);
	ft_set_2d_entry(&inter->size, elem->size);
}

void				ft_set_entry_1d(t_interface *inter, t_elem *elem)
{
	ft_set_1d_entry_int(&inter->fix.angle_rot, elem->angle_rot);
	ft_set_1d_entry_int(&inter->angle, elem->angle);
	ft_set_1d_entry_int(&inter->rad, elem->rad);
	ft_set_1d_entry_int(&inter->refract.pourcent, elem->refract.pourcent);
	ft_set_1d_entry_int(&inter->reflect.pourcent, elem->reflect.pourcent);
	ft_set_1d_entry_char(&inter->refract.material, elem->refract.material);
	ft_set_1d_entry_char(&inter->tex_c.name, elem->tex_c.name);
	ft_set_1d_entry_char(&inter->tex_n.name, elem->tex_n.name);
	ft_set_1d_entry_int(&inter->light.intensity, elem->intensity);
	ft_set_1d_entry_int(&inter->rayon_torre.r1, elem->rayon_torre.x);
	ft_set_1d_entry_int(&inter->rayon_torre.r2, elem->rayon_torre.y);
}
