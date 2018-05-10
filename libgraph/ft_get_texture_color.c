/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_texture_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:26:05 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/10 17:30:37 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_color	ft_get_texture_color(t_texture *textur, int x, int y)
{
	t_color color;

	ft_set_color(&color, 0, 0, 0);
	if (textur == NULL || textur->data == NULL)
		ft_error("Texture is NULL");
	if (x >= 0 && y >= 0)
	{
		if (x < textur->width && y < textur->height && textur->n == 3)
		{
			ft_set_color(&color,
				textur->data[(x * textur->n +
					y * textur->width * textur->n)],
				textur->data[(x * textur->n +
					y * textur->width * textur->n) + 1],
				textur->data[(x * textur->n +
					y * textur->width * textur->n) + 2]);
		}
	}
	return (color);
}
