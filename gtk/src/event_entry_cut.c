/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_entry_cut.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 11:59:45 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/23 12:28:07 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void		ft_event_entry_cut_3(t_event_entry *e, t_interface *inter)
{
	g_signal_connect(G_OBJECT(inter->cut.origin_5.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_5.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_5.z), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_5.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_5.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_5.z), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_6.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_6.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_6.z), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_6.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_6.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_6.z), "changed",
		G_CALLBACK(ft_entry_value), e);
}

static void		ft_event_entry_cut_2(t_event_entry *e, t_interface *inter)
{
	g_signal_connect(G_OBJECT(inter->cut.origin_3.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_3.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_3.z), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_3.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_3.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_3.z), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_4.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_4.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_4.z), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_4.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_4.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_4.z), "changed",
		G_CALLBACK(ft_entry_value), e);
}

static void		ft_event_entry_cut_1(t_event_entry *e, t_interface *inter)
{
	g_signal_connect(G_OBJECT(inter->cut.origin_1.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_1.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_1.z), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_1.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_1.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_1.z), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_2.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_2.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.origin_2.z), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_2.x), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_2.y), "changed",
		G_CALLBACK(ft_entry_value), e);
	g_signal_connect(G_OBJECT(inter->cut.axe_2.z), "changed",
		G_CALLBACK(ft_entry_value), e);
}

void			ft_event_entry_cut(t_event_entry *e, t_interface *inter)
{
	ft_event_entry_cut_1(e, inter);
	ft_event_entry_cut_2(e, inter);
	ft_event_entry_cut_3(e, inter);
}
