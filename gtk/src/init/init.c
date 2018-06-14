/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:17:15 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 11:47:41 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void		ft_init_1d_button(t_1d_button *button)
{
	button->label_x = NULL;
	button->x = NULL;
}

static void	ft_init_cont(t_interface *inter)
{
	inter->cont.principal = NULL;
	inter->cont.colonne0 = NULL;
	inter->cont.colonne1 = NULL;
	inter->cont.colonne2 = NULL;
	inter->cont.colonne3 = NULL;
	inter->cont.colonne4 = NULL;
	inter->cont.colonne5 = NULL;
}

static void	ft_init_prim(t_interface *inter)
{
	inter->prim.sphere = NULL;
	inter->angle.label_x = NULL;
	inter->angle.x = NULL;
	inter->rad.label_x = NULL;
	inter->rad.x = NULL;
	inter->prim.plan = NULL;
	inter->prim.cone = NULL;
	inter->prim.cylindre = NULL;
}

static void	ft_init_list(t_interface *inter)
{
	inter->list.store = NULL;
	inter->list.button = NULL;
}

void		ft_init(t_interface *inter)
{
	ft_init_list(inter);
	ft_init_cont(inter);
	ft_init_fix(inter);
	ft_init_prim(inter);
	ft_init_effect(inter);
	ft_init_sinus(inter);
	ft_init_checker(inter);
}
