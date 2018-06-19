/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:26:26 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/18 19:33:37 by tfavart          ###   ########.fr       */
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

void		ft_init_elem1(t_elem *elem)
{
	ft_set_2d(&elem->sinus.sin_x, 0, 0);
	ft_set_2d(&elem->sinus.sin_y, 0, 0);
	ft_set_2d(&elem->sinus.sin_z, 0, 0);
	ft_set_2d(&elem->rayon_torre, 0, 0);
	elem->checker.on_off = 0;
	ft_set_2d(&elem->checker.move, 0, 0);
	ft_set_2d(&elem->checker.scale, 0, 0);
	elem->intensity = 0;
	elem->sepia = 0;
	ft_set_2d(&elem->size, 0, 0);
}

static void	ft_init_elem2(t_elem *elem)
{
	elem->tex_n.on_off = 0;
	elem->tex_n.name = ft_strdup("texture");
	ft_set_2d(&elem->tex_n.move, 0, 0);
	ft_set_2d(&elem->tex_n.scale, 0, 0);
	elem->sinus.on_off = 0;
	ft_set_3d(&elem->triang.p1, 0, 0, 0);
	ft_set_3d(&elem->triang.p2, 0, 0, 0);
	ft_set_3d(&elem->triang.p3, 0, 0, 0);
	ft_init_elem1(elem);
}

void		ft_init_elem(t_elem *elem)
{
	elem->name = NULL;
	ft_set_3d(&elem->color, 0, 0, 0);
	ft_set_3d(&elem->pos, 0, 0, 0);
	ft_set_3d(&elem->translation, 0, 0, 0);
	ft_set_3d(&elem->rot, 0, 0, 0);
	elem->angle_rot = 0;
	elem->angle = 0;
	elem->rad = 0;
	ft_set_3d(&elem->vec, 0, 0, 0);
	elem->specular = 0;
	elem->reflect.on_off = 0;
	elem->reflect.pourcent = 0;
	elem->refract.on_off = 0;
	elem->refract.material = ft_strdup("material");
	elem->refract.pourcent = 0;
	elem->tex_c.on_off = 0;
	elem->tex_c.name = ft_strdup("texture");
	ft_set_2d(&elem->tex_c.move, 0, 0);
	ft_set_2d(&elem->tex_c.scale, 0, 0);
	ft_init_elem2(elem);
}
