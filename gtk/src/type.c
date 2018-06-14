/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:00:16 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 12:05:30 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void		ft_type_entry_1(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter)
{
	if (type == inter->fix.pos.x)
		*value = &elem->pos.x;
	if (type == inter->fix.pos.y)
		*value = &elem->pos.y;
	if (type == inter->fix.pos.z)
		*value = &elem->pos.z;
	if (type == inter->fix.translation.x)
		*value = &elem->translation.x;
	if (type == inter->fix.translation.y)
		*value = &elem->translation.y;
	if (type == inter->fix.translation.z)
		*value = &elem->translation.z;
	if (type == inter->fix.vec.x)
		*value = &elem->vec.x;
	if (type == inter->fix.vec.y)
		*value = &elem->vec.y;
	if (type == inter->fix.vec.z)
		*value = &elem->vec.z;
}

void		ft_type_entry_2(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter)
{
	if (type == inter->fix.rot.x)
		*value = &elem->rot.x;
	if (type == inter->fix.rot.y)
		*value = &elem->rot.y;
	if (type == inter->fix.rot.z)
		*value = &elem->rot.z;
	if (type == inter->fix.angle_rot.x)
		*value = &elem->angle_rot;
	if (type == inter->fix.color.x)
		*value = &elem->color.x;
	if (type == inter->fix.color.y)
		*value = &elem->color.y;
	if (type == inter->fix.color.z)
		*value = &elem->color.z;
	if (type == inter->tex_c.move.x)
		*value = &elem->tex_c.move.x;
	if (type == inter->tex_c.move.y)
		*value = &elem->tex_c.move.y;
	if (type == inter->tex_c.scale.x)
		*value = &elem->tex_c.scale.x;
	if (type == inter->tex_c.scale.y)
		*value = &elem->tex_c.scale.y;
}

void		ft_type_entry_3(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter)
{
	if (type == inter->tex_n.move.x)
		*value = &elem->tex_n.move.x;
	if (type == inter->tex_n.move.y)
		*value = &elem->tex_n.move.y;
	if (type == inter->tex_n.scale.x)
		*value = &elem->tex_n.scale.x;
	if (type == inter->tex_n.scale.y)
		*value = &elem->tex_n.scale.y;
	if (type == inter->reflect.pourcent.x)
		*value = &elem->reflect.pourcent;
	if (type == inter->refract.pourcent.x)
		*value = &elem->refract.pourcent;
	if (type == inter->rad.x)
		*value = &elem->rad;
	if (type == inter->angle.x)
		*value = &elem->angle;
}