/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_universe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:41:38 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/29 16:06:18 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rt_tf.h"

void	ft_multi_spot(t_obj *obj, t_prim *small, t_color *color, t_3dpt *origin)
{
	t_light	*light;
	t_obj	perspot;

	perspot.prim = obj->prim;
	light = obj->light;
	ft_set_color(color, 0, 0, 0);
	while (light != NULL)
	{
		perspot.light = light;
		if (light->type == LIGHT || light->type == SUN)
			ft_check_lit(&perspot, small, color, origin);
		else if (light->type == AMBIANT)
			ft_get_ambiant(small, color, perspot.light);
		light = light->next;
	}
}

t_prim	*ft_find_closest(t_prim *prim)
{
	t_prim *smallest;
	t_prim *start;

	smallest = NULL;
	start = prim;
	while (prim != NULL)
	{
		if (prim->t >= 0)
		{
			smallest = prim;
			break ;
		}
		prim = prim->next;
	}
	prim = start;
	while (prim != NULL)
	{
		if (prim->t >= 0)
		{
			if (prim->t < (smallest->t + 0.001))
				smallest = prim;
		}
		prim = prim->next;
	}
	return (smallest);
}

t_color	ft_figure_color(t_obj *obj, t_3dpt *origin, t_prim *prev)
{
	t_prim	*smallest;
	t_color	color;

	smallest = ft_find_closest_exclude(obj->prim, prev);
	if (smallest == NULL)
	{
		ft_set_color(&color, 0, 0, 0);
		return (color);
	}
	ft_multi_spot(obj, smallest, &color, origin);
	return (color);
}
