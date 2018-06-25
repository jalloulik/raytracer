/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:17:15 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/23 10:59:22 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void		ft_init_1d_button(t_1d_button *button)
{
	button->box_h = NULL;
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
	inter->cont.colonne6 = NULL;
	inter->cont.colonne7 = NULL;
	inter->cont.colonne8 = NULL;
	inter->cont.colonne9 = NULL;
}

static void	ft_init_prim(t_interface *inter)
{
	inter->render = NULL;
	inter->prim.sphere = NULL;
	inter->prim.plan = NULL;
	inter->prim.cone = NULL;
	inter->prim.cylindre = NULL;
	inter->prim.carre = NULL;
	inter->prim.cercle = NULL;
	inter->prim.triangle = NULL;
	inter->prim.torre = NULL;
	inter->light.spot = NULL;
	inter->light.sun = NULL;
	inter->light.ambiant = NULL;
}

static void	ft_init_list(t_interface *inter)
{
	inter->list.store = NULL;
	inter->list.button = NULL;
	ft_init_1d_button(&(inter->light.intensity));
	ft_init_1d_button(&(inter->angle));
	ft_init_1d_button(&(inter->rad));
	ft_init_1d_button(&(inter->specular));
	ft_init_2d_button(&(inter->size));
	ft_init_1d_button(&(inter->sepia));
	ft_init_1d_button(&(inter->rayon_torre.r1));
	ft_init_1d_button(&(inter->rayon_torre.r2));
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
	ft_init_cut(inter);
}
