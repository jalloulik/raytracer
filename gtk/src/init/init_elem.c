/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:26:26 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/23 09:33:41 by tfavart          ###   ########.fr       */
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
	ft_set_2d(&elem->sinus.sin_x, 1, 1);
	ft_set_2d(&elem->sinus.sin_y, 1, 1);
	ft_set_2d(&elem->sinus.sin_z, 1, 1);
	ft_set_2d(&elem->rayon_torre, 2, 1);
	elem->checker.on_off = 0;
	ft_set_2d(&elem->checker.move, 0, 0);
	ft_set_2d(&elem->checker.scale, 1, 1);
	elem->intensity = 100;
	elem->sepia = 0;
	ft_set_3d(&elem->cut.origin_5, 0, 0, 0);
	ft_set_3d(&elem->cut.axe_5, 0, 0, 0);
	ft_set_3d(&elem->cut.origin_6, 0, 0, 0);
	ft_set_3d(&elem->cut.axe_6, 0, 0, 0);
	elem->cut.on_off = 0;
	ft_set_2d(&elem->size, 2, 2);
}

static void	ft_init_elem2(t_elem *elem)
{
	elem->tex_n.on_off = 0;
	elem->tex_n.name = ft_strdup("Stone_02_NRM.tga");
	ft_set_2d(&elem->tex_n.move, 0, 0);
	ft_set_2d(&elem->tex_n.scale, 1, 1);
	elem->sinus.on_off = 0;
	ft_set_3d(&elem->triang.p1, 0, 0, 0);
	ft_set_3d(&elem->triang.p2, 0, 0, 0);
	ft_set_3d(&elem->triang.p3, 0, 0, 0);
	ft_set_3d(&elem->cut.origin_1, 0, 0, 0);
	ft_set_3d(&elem->cut.axe_1, 0, 0, 0);
	ft_set_3d(&elem->cut.origin_2, 0, 0, 0);
	ft_set_3d(&elem->cut.axe_2, 0, 0, 0);
	ft_set_3d(&elem->cut.origin_3, 0, 0, 0);
	ft_set_3d(&elem->cut.axe_3, 0, 0, 0);
	ft_set_3d(&elem->cut.origin_4, 0, 0, 0);
	ft_set_3d(&elem->cut.axe_4, 0, 0, 0);
	ft_init_elem1(elem);
}

void		ft_init_elem(t_elem *elem)
{
	elem->name = NULL;
	ft_set_3d(&elem->color, 255, 255, 255);
	ft_set_3d(&elem->pos, 0, 0, 0);
	ft_set_3d(&elem->translation, 0, 0, 0);
	ft_set_3d(&elem->rot, 0, 1, 0);
	elem->angle_rot = 0;
	elem->angle = 45;
	elem->rad = 2;
	ft_set_3d(&elem->vec, 0, 1, 0);
	elem->specular = 1;
	elem->reflect.on_off = 0;
	elem->reflect.pourcent = 0;
	elem->refract.on_off = 0;
	elem->refract.material = ft_strdup("AIR");
	elem->refract.pourcent = 0;
	elem->tex_c.on_off = 0;
	elem->tex_c.name = ft_strdup("Stone_02_COLOR.tga");
	ft_set_2d(&elem->tex_c.move, 0, 0);
	ft_set_2d(&elem->tex_c.scale, 1, 1);
	ft_init_elem2(elem);
}
