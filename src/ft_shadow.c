/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:00:08 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/21 16:56:01 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_check_obst(t_3dpt *o, t_prim *obst, t_l_p *light_path)
{
	double	t;

	t = ft_return_prim_dist(obst, &(light_path->p_to_light), o);
	if (t >= 0 && t < light_path->dist)
		return (0);
	else
		return (1);
}

void	ft_resolve_single_prim(t_prim *prim, t_3dpt *ray_dir, t_3dpt *origin)
{
	double t;

	t = ft_return_prim_dist(prim, ray_dir, origin);
	if (t > 0)
	{
		ft_calculate_vec_end(&(prim->p), origin,
										ray_dir, t);
		ft_calculate_normal(prim, &(prim->p));
	}
}

void	ft_shad_rfrct(t_prim *prim, t_prim *small, t_color *clr, t_l_p *l_path)
{
	l_path->percent = (l_path->percent + (1 - prim->refract_ratio)) / 2;
	if (prim->textur.valid == TRUE || prim->checkers.valid == TRUE)
	{
		ft_resolve_single_prim(prim, &(l_path->p_to_light), &(small->p));
		ft_get_prim_texture_color_main(prim);
		ft_shadow_texture(clr, &(prim->color2));
	}
}

void	ft_light_path(t_obj *obj, t_prim *small, t_l_p *light_path)
{
	light_path->dist = ft_get_dist_to_light(obj, small);
	ft_calculate_vec_to_light(&(light_path->p_to_light), obj, small);
}

double	ft_shadow_percent(t_obj *obj, t_prim *small, int *lit, t_color *color)
{
	t_prim	*prim;
	t_l_p	light_path;

	light_path.percent = 1;
	prim = obj->prim;
	ft_light_path(obj, small, &light_path);
	while (prim != NULL)
	{
		if (prim != small)
		{
			*lit = ft_check_obst(&(small->p), prim, &light_path);
			if (*lit == 0)
			{
				if (prim->refractive == 1)
					ft_shad_rfrct(prim, small, color, &light_path);
				else
					light_path.percent = (light_path.percent + 1) / 2;
			}
		}
		prim = prim->next;
	}
	return (light_path.percent);
}
