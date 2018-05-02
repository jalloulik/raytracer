/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:58:09 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/20 11:59:07 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		trace_ray(t_mlx *mlx, t_list *object)
{
	int		i;
	int		j;
	t_color	color;

	j = 0;
	while (j++ < mlx->height)
	{
		i = 0;
		while (i++ < mlx->width)
		{
			color = intersec(mlx, i, j, object);
			fill_pixel(mlx, i, j, color.color);
		}
		affiche(mlx);
	}
}
