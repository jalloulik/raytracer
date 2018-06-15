/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:13:56 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/15 12:13:57 by tfavart          ###   ########.fr       */
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
	if (type == inter->checker.move.x)
		*value = &elem->checker.move.x;
	if (type == inter->checker.move.y)
		*value = &elem->checker.move.y;
	if (type == inter->checker.scale.x)
		*value = &elem->checker.scale.x;
	if (type == inter->checker.scale.y)
		*value = &elem->checker.scale.y;
}

void		ft_type_entry_4(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter)
{
	if (type == inter->sinus.sin_x.x)
		*value = &elem->sinus.sin_x.x;
	if (type == inter->sinus.sin_x.y)
		*value = &elem->sinus.sin_x.y;
	if (type == inter->sinus.sin_y.x)
		*value = &elem->sinus.sin_y.x;
	if (type == inter->sinus.sin_y.y)
		*value = &elem->sinus.sin_y.y;
	if (type == inter->sinus.sin_z.x)
		*value = &elem->sinus.sin_z.x;
	if (type == inter->sinus.sin_z.y)
		*value = &elem->sinus.sin_z.y;
	if (type == inter->light.intensity.x)
		*value = &elem->intensity;
}
