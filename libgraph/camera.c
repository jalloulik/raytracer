/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:51:26 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/24 14:50:42 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	exeption(t_mlx *mlx, t_vect *dir, int x, int y)
{
	t_vect	*v;

	v = mlx->camera_dir;
	if (v->x == 0 && v->z == 0)
	{
		dir->x = (mlx->h / 2) - mlx->pitch * x;
		dir->y = v->y;
		dir->z = (mlx->h / 2) - mlx->pitch * y;
		v_unit(dir);
		return (1);
	}
	return (0);
}

void		calc_ray(t_mlx *mlx, t_vect *dir, double x, double y)
{
	t_vect	uv;
	t_vect	*i;
	t_vect	*j;
	t_vect	*k;

	if (exeption(mlx, dir, x, y))
		return ;
	uv.x = (mlx->h / 2) - mlx->pitch * x;
	uv.y = (mlx->h / 2) - mlx->pitch * y;
	k = mlx->camera_dir;
	v_unit(k);
	j = new_vect(0, 1, 0);
	i = v_cross(k, j);
	v_unit(i);
	free(j);
	j = v_cross(i, k);
	dir->x = uv.x * i->x + uv.y * j->x + k->x;
	dir->y = uv.x * i->y + uv.y * j->y + k->y;
	dir->z = uv.x * i->z + uv.y * j->z + k->z;
	free(i);
	free(j);
	v_unit(dir);
}

void		read_camera(t_mlx *mlx, int fd)
{
	mlx->camera_pos = read_vect(fd);
	mlx->camera_dir = read_vect(fd);
	v_unit(mlx->camera_dir);
}

void		read_light(t_mlx *mlx, int fd)
{
	mlx->light = read_vect(fd);
}
