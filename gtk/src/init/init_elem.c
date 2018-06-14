/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:26:26 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/12 15:17:46 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void		ft_set_3d(t_3d *elem, int x, int y, int z)
{
	elem->x = x;
	elem->y = y;
	elem->z = z;
}

void		ft_set_2d(t_2d *elem, int x, int y)
{
	elem->x = x;
	elem->y = y;
}

void		ft_init_elem(t_elem *elem)
{
	ft_set_3d(&elem->color, 0, 0, 0);
	ft_set_3d(&elem->pos, 0, 0, 0);
	ft_set_3d(&elem->translation, 0, 0, 0);
	ft_set_3d(&elem->rot, 0, 0, 0);
	elem->angle = 0;
	ft_set_3d(&elem->vec, 0, 0, 0);
	elem->specular = 0;
	elem->refract.on_off = 0;
	elem->reflect.on_off = 0;
	elem->tex_c.on_off = 0;
	elem->tex_c.name = NULL;
	ft_set_2d(&elem->tex_c.move, 0, 0);
	ft_set_2d(&elem->tex_c.scale, 0, 0);
	elem->tex_n.on_off = 0;
	elem->tex_n.name = NULL;
	ft_set_2d(&elem->tex_n.move, 0, 0);
	ft_set_2d(&elem->tex_n.scale, 0, 0);
	elem->sinus.on_off = 0;
	ft_set_2d(&elem->sinus.sin_x, 0, 0);
	ft_set_2d(&elem->sinus.sin_y, 0, 0);
	ft_set_2d(&elem->sinus.sin_z, 0, 0);
	elem->checker.on_off = 0;
	ft_set_2d(&elem->checker.move, 0, 0);
	ft_set_2d(&elem->checker.scale, 0, 0);
}