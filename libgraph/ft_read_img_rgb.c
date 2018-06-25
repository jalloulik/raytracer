/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_img_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:44:00 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/04 14:24:58 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_color	ft_read_img_rgb(t_mlximg *img, int x, int y)
{
	int		opp;
	int		i;
	t_color color;

	ft_set_color(&color, 0, 0, 0);
	if (img == NULL)
		ft_error("Image does not exist");
	if ((x >= 0) && (y >= 0) && (x < img->length)
								&& (y < img->height))
	{
		opp = img->bpp / 8;
		i = (x * opp) + (y * img->s_l);
		color.blue = img->str[i];
		color.green = img->str[i + 1];
		color.red = img->str[i + 2];
	}
	return (color);
}
