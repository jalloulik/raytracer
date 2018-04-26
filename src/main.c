/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:04:27 by kjalloul          #+#    #+#             */
/*   Updated: 2018/04/26 08:45:59 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_get_first_ray(t_ray *ray, t_cam *cam, t_2dpt *pos)
{
	ray->vpcurrent.x = cam->vp.vplr.x + (cam->vdr.x * cam->vp.xindent *
		(double)(pos->x)) - (cam->vdu.x * cam->vp.yindent * (double)(pos->y));
	ray->vpcurrent.y = cam->vp.vplr.y + (cam->vdr.y * cam->vp.xindent *
		(double)(pos->x)) - (cam->vdu.y * cam->vp.yindent * (double)(pos->y));
	ray->vpcurrent.z = cam->vp.vplr.z + (cam->vdr.z * cam->vp.xindent *
		(double)(pos->x)) - (cam->vdu.z * cam->vp.yindent * (double)(pos->y));
	ft_calculate_vector(&(ray->dir), &(cam->origin), &(ray->vpcurrent));
}

void	ft_set_scene(t_winenv *mlxenv, t_cam *cam, t_light *light, t_prim *list)
{
	t_2dpt		pos;
	t_ray		ray;

	pos.x = -1;
	cam->vp.pos = &pos;
	ray.cam = cam;
	ft_get_topleft_indent(cam);
	ft_rotate_all(list);
	ft_translante_all(list);
	ft_create_local_vector_spaces(list);
	while (++pos.x < WIN_WIDTH)
	{
		pos.y = -1;
		while (++pos.y < WIN_HEIGHT)
		{
			ft_get_first_ray(&ray, cam, &pos);
			ft_resolve_prim(list, &ray, cam);
			ft_figure_color(list, &ray, light);
			ft_fill_img_rgb(mlxenv->img, pos.x, pos.y, ray.color2);
		}
	}
}

void	ft_controller_rt(t_cam *cam, t_light *light, t_prim *list)
{
	t_winenv mlxenv;

	ft_mlx_init(&mlxenv);
	ft_create_window(&mlxenv, WIN_WIDTH, WIN_HEIGHT, "rtv1");
	ft_create_img(&mlxenv, WIN_WIDTH, WIN_HEIGHT);
	ft_set_scene(&mlxenv, cam, light, list);
	mlx_put_image_to_window(mlxenv.mlxptr, mlxenv.win, mlxenv.img.ptr, 0, 0);
	mlx_key_hook(mlxenv.win, &ft_keyhook, NULL);
	mlx_loop(mlxenv.mlxptr);
}

int		main(int ac, char **av)
{
	t_cam	cam;
	t_light	*light;
	t_prim	*list;

	list = NULL;
	light = NULL;
	if (ac != 2)
		ft_error(ERRUSAGE);
	ft_parsing_start(av[1], &cam, &light, &list);
	ft_controller_rt(&cam, light, list);
	return (0);
}
