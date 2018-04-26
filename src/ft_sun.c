/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:17:40 by tfavart           #+#    #+#             */
/*   Updated: 2018/04/26 13:32:41 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rt_tf.h"

static t_light	*ft_get_last_spot(t_light *last)
{
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void			ft_sun_setup(char **tab, t_light **spots)
{
	t_light		*last;
	t_light		*list;
	char		**tmp;

	list = *spots;
	list = ft_add_lst_light(list, SUN);
	*spots = list;
	last = ft_get_last_spot(list);
	if (ft_count_tab(tab) < 3)
		ft_error(ERRSPOT);
	tmp = ft_strsplit(tab[1], ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "origin") == 0)
		ft_error(ERRSPOT);
	ft_set_3dpt(&(last->origin), (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_free_tab(tmp);
	tmp = ft_strsplit(tab[2], ':');
	if (ft_count_tab(tmp) != 2 || ft_strequ(tmp[0], "intensity") == 0)
		ft_error(ERRSPOT);
	last->intensity = (double)ft_atoi(tmp[1]) / 100;
	if (last->intensity < 0 || last->intensity > 2)
		ft_error("Spot intensity needs to be between 0 and 200");
	ft_free_tab(tmp);
	ft_set_color(&(last->color), 255, 255, 255);
}

void			ft_check_sun(t_prim *list, t_prim *small, t_light *light,
t_ray *ray)
{
	t_3dpt		p_to_light;
	double		dist_to_light;
	int			lit;

	ft_set_3dpt(&p_to_light, 0, 0, 0);
	dist_to_light = ft_calculate_dist(&p_to_light, &(light->origin));
	ft_calculate_vector(&p_to_light, &p_to_light, &(light->origin));
	while (list != NULL)
	{
		if (list != small)
		{
			lit = ft_check_obst(&(small->p), &p_to_light, list, dist_to_light);
			if (lit == 0)
				return ;
		}
		list = list->next;
	}
	light->dotd = ft_calculate_dot(&p_to_light, &(small->normal));
	if (light->dotd >= 0 && light->dotd <= 1)
	{
		ft_get_dotr(small, light, &p_to_light, ray);
		ft_get_shade(small, ray, light);
	}
}
