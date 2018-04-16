/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_universe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:41:38 by kjalloul          #+#    #+#             */
/*   Updated: 2018/03/22 09:04:53 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_multi_spot(t_prim *list, t_prim *small, t_light *light, t_ray *ray)
{
	ft_set_color(&(ray->color2), 0, 0, 0);
	while (light != NULL)
	{
		ft_check_lit(list, small, light, ray);
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

void	ft_figure_color(t_prim *prim, t_ray *ray, t_light *light)
{
	t_prim *smallest;

	smallest = ft_find_closest(prim);
	if (smallest == NULL)
	{
		ft_set_color(&(ray->color2), 0, 0, 0);
		return ;
	}
	ft_multi_spot(prim, smallest, light, ray);
}
