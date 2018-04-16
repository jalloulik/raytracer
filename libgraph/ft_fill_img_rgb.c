/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_img_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:52:16 by kjalloul          #+#    #+#             */
/*   Updated: 2018/02/19 15:33:19 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_fill_img_rgb(t_mlximg img, int x, int y, t_color color)
{
	int		opp;
	int		i;

	if ((x >= 0) && (y >= 0) && (x < img.length)
								&& (y < img.height))
	{
		opp = img.bpp / 8;
		i = (x * opp) + (y * img.s_l);
		img.str[i] = color.blue;
		img.str[i + 1] = color.green;
		img.str[i + 2] = color.red;
		img.str[i + 3] = 0;
	}
}
