/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:52:22 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 13:04:50 by tfavart          ###   ########.fr       */
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

void			ft_event(t_event_entry *e, t_interface *inter)
{
	g_signal_connect(G_OBJECT(inter->list.button), "changed",
		G_CALLBACK(ft_select_elem_actif), e);
	ft_event_button(e, inter);
	ft_event_entry1(e, inter);
	ft_event_entry2(e, inter);
	ft_event_entry3(e, inter);
	ft_event_entry4(e, inter);
	ft_event_switch(e, inter);
}
