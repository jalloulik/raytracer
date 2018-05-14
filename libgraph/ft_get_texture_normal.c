/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_texture_normal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:38:44 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/11 14:04:32 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_get_texture_normal(t_3dpt *normal, t_texture *textur, int x, int y)
{
	if (textur == NULL || textur->data == NULL)
		ft_error("Texture is NULL");
	if (x >= 0 && y >= 0)
	{
		if (x < textur->width && y < textur->height && textur->n == 3)
		{
			ft_set_3dpt(normal,
				textur->data[(x * textur->n +
					y * textur->width * textur->n)],
				textur->data[(x * textur->n +
					y * textur->width * textur->n) + 1],
				textur->data[(x * textur->n +
					y * textur->width * textur->n) + 2]);
		}
	}
}
