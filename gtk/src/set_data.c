/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:01:39 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/18 13:45:10 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void		ft_set_entry_3d(t_interface *inter, t_elem *elem)
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

static void		ft_set_entry_2d(t_interface *inter, t_elem *elem)
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
}

static void		ft_set_entry_1d(t_interface *inter, t_elem *elem)
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

static void		ft_set_data(t_interface *inter, t_elem *elem)
{
	ft_set_entry_3d(inter, elem);
	ft_set_entry_2d(inter, elem);
	ft_set_entry_1d(inter, elem);
	gtk_switch_set_active(GTK_SWITCH(inter->specular.x),
		elem->specular);
	gtk_switch_set_active(GTK_SWITCH(inter->reflect.on_off.x),
		elem->reflect.on_off);
	gtk_switch_set_active(GTK_SWITCH(inter->refract.on_off.x),
		elem->refract.on_off);
	gtk_switch_set_active(GTK_SWITCH(inter->tex_c.on_off.x),
		elem->tex_c.on_off);
	gtk_switch_set_active(GTK_SWITCH(inter->tex_n.on_off.x),
		elem->tex_n.on_off);
	gtk_switch_set_active(GTK_SWITCH(inter->sinus.on_off.x),
		elem->sinus.on_off);
	gtk_switch_set_active(GTK_SWITCH(inter->checker.on_off.x),
		elem->checker.on_off);
	gtk_switch_set_active(GTK_SWITCH(inter->sepia.x), elem->sepia);
}

void			ft_select_elem_actif(GtkWidget *widget, gpointer data)
{
	t_event_entry	*e;
	t_elem			*elem;

	e = (t_event_entry *)data;
	elem = e->inter->list_e;
	(void)widget;
	if (gtk_combo_box_get_active_iter(GTK_COMBO_BOX(e->inter->list.button),
		&e->iter))
	{
		while (elem)
		{
			gtk_tree_model_get(GTK_TREE_MODEL(e->inter->list.store),
			&e->iter, 0, &e->index1, 1, &e->p_text1, -1);
			gtk_tree_model_get(GTK_TREE_MODEL(e->inter->list.store),
			&elem->iter, 0, &e->index2, 1, &e->p_text2, -1);
			if (ft_strcmp(e->p_text1, e->p_text2) == 0)
			{
				ft_set_data_show(e->inter, elem);
				ft_set_data(e->inter, elem);
				break ;
			}
			elem = elem->next;
		}
	}
}
