/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:41:09 by kjalloul          #+#    #+#             */
/*   Updated: 2018/01/15 13:46:48 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_fill_img(t_mlximg img, int x, int y, int color)
{
	int		opp;
	int		i;

	if ((x >= 0) && (y >= 0) && (x < img.length)
								&& (y < img.height))
	{
		opp = img.bpp / 8;
		i = (x * opp) + (y * img.s_l);
		img.str[i] = color;
		img.str[i + 1] = color >> 8;
		img.str[i + 2] = color >> 16;
		img.str[i + 3] = 0;
	}
}
