/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:59:55 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 13:11:40 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void		ft_event_entry1(t_event_entry *e, t_interface *inter)
{
	g_signal_connect(G_OBJECT(inter->fix.pos.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->fix.pos.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->fix.pos.z), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->fix.translation.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->fix.translation.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->fix.translation.z), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->fix.vec.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->fix.vec.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->fix.vec.z), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->fix.rot.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->fix.rot.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->fix.rot.z), "changed",
			G_CALLBACK(ft_entry_value), e);
}

void		ft_event_entry2(t_event_entry *e, t_interface *inter)
{
	g_signal_connect(G_OBJECT(inter->fix.angle_rot.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->fix.color.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->fix.color.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->fix.color.z), "changed",
			G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->tex_c.name.x), "changed",
			G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->tex_n.name.x), "changed",
			G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->tex_c.move.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->tex_c.move.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->tex_c.scale.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->tex_c.scale.y), "changed",
		G_CALLBACK(ft_entry_value), e);
}

void		ft_event_entry3(t_event_entry *e, t_interface *inter)
{
	g_signal_connect(G_OBJECT(inter->tex_n.move.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->tex_n.move.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->tex_n.scale.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->tex_n.scale.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->reflect.pourcent.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->refract.pourcent.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->refract.material.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->rad.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->angle.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->checker.move.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->checker.move.y), "changed",
		G_CALLBACK(ft_entry_value), e);
}

void		ft_event_entry4(t_event_entry *e, t_interface *inter)
{
	g_signal_connect(G_OBJECT(inter->checker.scale.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->checker.scale.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->sinus.sin_x.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->sinus.sin_x.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->sinus.sin_y.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->sinus.sin_y.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->sinus.sin_z.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->sinus.sin_z.y), "changed",
		G_CALLBACK(ft_entry_value), e);
}
