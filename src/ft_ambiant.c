/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ambiant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 08:07:13 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 15:59:54 by kjalloul         ###   ########.fr       */
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

void			ft_ambiant_setup(t_node *node, t_light **spots)
{
	t_light		*last;
	t_light		*list;
	char		*content;

	list = *spots;
	list = ft_add_lst_light(list, AMBIANT);
	*spots = list;
	last = ft_get_last_spot(list);
	content = xmlp_get_child_node_content(node, "ambiant/intensity");
	last->intensity = (double)ft_atoi(content) / 100;
	if (last->intensity < 0 || last->intensity > 2)
		ft_error("Spot intensity needs to be between 0 and 200");
}

void			ft_get_ambiant(t_prim *prim, t_color *color, t_light *light)
{
	int			r;
	int			g;
	int			b;

	if (prim->textur.valid == TRUE)
		prim->color2 = ft_get_prim_texture_color(prim);
	r = color->red + prim->color2.red * light->intensity;
	g = color->green + prim->color2.green * light->intensity;
	b = color->blue + prim->color2.blue * light->intensity;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	color->red = (unsigned char)r;
	color->green = (unsigned char)g;
	color->blue = (unsigned char)b;
	color->alpha = 0;
}
