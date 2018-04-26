/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ambiant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 08:07:13 by tfavart           #+#    #+#             */
/*   Updated: 2018/04/26 13:25:50 by tfavart          ###   ########.fr       */
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

void			ft_ambiant_setup(char **tab, t_light **spots)
{
	t_light		*last;
	t_light		*list;
	char		**tmp;

	list = *spots;
	list = ft_add_lst_light(list, AMBIANT);
	*spots = list;
	last = ft_get_last_spot(list);
	if (ft_count_tab(tab) < 2)
		ft_error(ERRSPOT);
	tmp = ft_strsplit(tab[1], ':');
	if (ft_count_tab(tmp) != 2 || ft_strequ(tmp[0], "intensity") == 0)
		ft_error(ERRSPOT);
	last->intensity = (double)ft_atoi(tmp[1]) / 100;
	ft_free_tab(tmp);
}

void			ft_get_ambiant(t_prim *prim, t_ray *ray, t_light *light)
{
	int			r;
	int			g;
	int			b;

	r = ray->color2.red + prim->color2.red * light->intensity;
	g = ray->color2.green + prim->color2.green * light->intensity;
	b = ray->color2.blue + prim->color2.blue * light->intensity;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	ray->color2.red = (unsigned char)r;
	ray->color2.green = (unsigned char)g;
	ray->color2.blue = (unsigned char)b;
	ray->color2.alpha = 0;
}

void			ft_check_ambiant(t_prim *small, t_light *light, t_ray *ray)
{
	ft_get_ambiant(small, ray, light);
}
