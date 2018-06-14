/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:52:22 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 11:57:35 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void		ft_event_button(t_event_entry *e, t_interface *inter)
{
	g_signal_connect(G_OBJECT(inter->prim.sphere), "clicked",
		G_CALLBACK(ft_create_sphere), inter);
	g_signal_connect(G_OBJECT(inter->prim.cone), "clicked",
		G_CALLBACK(ft_create_cone), inter);
	g_signal_connect(G_OBJECT(inter->prim.cylindre), "clicked",
		G_CALLBACK(ft_create_cylindre), inter);
	g_signal_connect(G_OBJECT(inter->prim.plan), "clicked",
		G_CALLBACK(ft_create_plan), inter);
	g_signal_connect(G_OBJECT(inter->list.button), "changed",
		G_CALLBACK(ft_select_elem_actif), e);
}

static void		ft_event_switch(t_event_entry *e, t_interface *inter)
{
	g_signal_connect(G_OBJECT(inter->specular.x), "notify::active",
		G_CALLBACK(ft_active_switch), e);
	g_signal_connect(G_OBJECT(inter->reflect.on_off.x), "notify::active",
		G_CALLBACK(ft_active_switch), e);
	g_signal_connect(G_OBJECT(inter->refract.on_off.x), "notify::active",
		G_CALLBACK(ft_active_switch), e);
	g_signal_connect(G_OBJECT(inter->tex_c.on_off.x), "notify::active",
		G_CALLBACK(ft_active_switch), e);
	g_signal_connect(G_OBJECT(inter->tex_n.on_off.x), "notify::active",
		G_CALLBACK(ft_active_switch), e);
	g_signal_connect(G_OBJECT(inter->sinus.on_off.x), "notify::active",
		G_CALLBACK(ft_active_switch), e);
	g_signal_connect(G_OBJECT(inter->checker.on_off.x), "notify::active",
		G_CALLBACK(ft_active_switch), e);
}

static void		ft_event_entry1(t_event_entry *e, t_interface *inter)
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

static void		ft_event_entry2(t_event_entry *e, t_interface *inter)
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

static void		ft_event_entry3(t_event_entry *e, t_interface *inter)
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
	
}

void		ft_event(t_event_entry *e, t_interface *inter)
{
	g_signal_connect(G_OBJECT(inter->list.button), "changed",
		G_CALLBACK(ft_select_elem_actif), e);
	ft_event_button(e, inter);
	ft_event_entry1(e, inter);
	ft_event_entry2(e, inter);
	ft_event_entry3(e, inter);
	ft_event_switch(e, inter);
}