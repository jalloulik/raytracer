/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:59:24 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/22 20:46:23 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				key_hook(int keycode, void *p)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)(p);
	if (keycode == ECHAP)
		exit(0);
	if (keycode == SPACE)
	{
		if (mlx->ombre)
			mlx->ombre = 0;
		else
			mlx->ombre = 1;
		clear_im(mlx, mlx->image.im);
		trace_ray(mlx, mlx->object);
	}
	return (0);
}
