/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:04:27 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/21 20:03:54 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rt_tf.h"

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

t_color	ft_throw_ray(t_obj *obj, t_3dpt *ray_dir, t_3dpt *origin, t_prim *prev)
{
	t_color		total_color;

	ft_set_color(&total_color, 0, 0, 0);
	ft_resolve_prim(obj->prim, ray_dir, origin);
	// ft_resolve_light(obj->light, ray_dir, origin);
	// if (ft_test_smallest(obj->light, obj->prim) == 1)
	// 	ft_set_color(&total_color, 255, 255, 255);
	// else
	// {
		total_color = ft_figure_color(obj, origin, prev);
	// }
	return (total_color);
}

void	ft_set_scene(t_winenv *mlxenv, t_cam *cam, t_light *light, t_prim *list)
{
	t_2dpt		pos;
	t_ray		ray;
	t_obj		obj;
	t_color		total_color;
	// t_texture	textur;

	// ft_stb_load_textur(&textur, "assets/Stone_02_COLOR.tga");
	obj.light = light;
	obj.prim = list;
	pos.x = -1;
	cam->vp.pos = &pos;
	ray.cam = cam;
	ft_get_topleft_indent(cam);
	ft_rotate_all(obj.prim);
	ft_translante_all(obj.prim);
	ft_create_local_vector_spaces(obj.prim);
	while (++pos.x < WIN_WIDTH)
	{
		pos.y = -1;
		while (++pos.y < WIN_HEIGHT)
		{
			ft_get_first_ray(&ray, cam, &pos);
			g_limit = 0;
			total_color = ft_trace_ray(&obj, &(ray.dir), &(cam->origin), NULL);
			if (cam->sepia == TRUE)
				ft_sepia_filter(&total_color);
			ft_fill_img_rgb(mlxenv->img, pos.x, pos.y, total_color);
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
