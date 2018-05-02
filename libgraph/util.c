/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:16:18 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 07:32:15 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	*new_vect(double x, double y, double z)
{
	t_vect	*new;

	new = ft_memalloc(sizeof(*new));
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

double	calc_height_screen(t_mlx *mlx)
{
	return (tan(mlx->fov / 2) * 2);
}
