/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:45:00 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/20 18:21:51 by kjalloul         ###   ########.fr       */
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

void			ft_spot_setup(t_node *node, t_light **spots)
{
	t_light	*last;
	t_light	*list;
	char	*content;

	content = NULL;
	list = *spots;
	list = ft_add_lst_light(list, LIGHT);
	*spots = list;
	last = ft_get_last_spot(list);
	content = xmlp_get_child_node_content(node, "spot/origin");
	if (content == NULL)
		ft_error("Spot needs origin");
	ft_set_3dpt_from_string(&(last->origin), content);
	content = xmlp_get_child_node_content(node, "spot/intensity");
	last->intensity = (double)ft_atoi(content) / 100;
	if (last->intensity < 0 || last->intensity > 2)
		ft_error("Spot intensity needs to be between 0 and 200");
	last->prim.sphere.radius = 1;
	ft_set_color(&(last->color), 255, 255, 255);
}
