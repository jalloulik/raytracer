/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:38:15 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/21 15:07:56 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_get_topleft_indent(t_cam *cam)
{
	cam->vp.vplr.x = cam->origin.x + ((cam->vd.x * cam->vp.dist) +
		(cam->vdu.x * (cam->vp.height / 2.0))) -
		(cam->vdr.x * (cam->vp.width / 2.0));
	cam->vp.vplr.y = cam->origin.y + ((cam->vd.y * cam->vp.dist) +
		(cam->vdu.y * (cam->vp.height / 2.0))) -
		(cam->vdr.y * (cam->vp.width / 2.0));
	cam->vp.vplr.z = cam->origin.z + ((cam->vd.z * cam->vp.dist) +
		(cam->vdu.z * (cam->vp.height / 2.0))) -
		(cam->vdr.z * (cam->vp.width / 2.0));
	cam->vp.xindent = cam->vp.width / WIN_WIDTH;
	cam->vp.yindent = cam->vp.height / WIN_HEIGHT;
}

void	ft_init_sphere(t_sphere *sphr, t_3dpt origin, double radius, int color)
{
	ft_set_3dpt(&(sphr->origin), origin.x, origin.y, origin.z);
	sphr->radius = radius;
	sphr->color = color;
}

void	ft_init_cam_vectors(t_cam *cam)
{
	ft_sum_vectors(&(cam->origin), &(cam->origin), &(cam->transl));
	ft_quater_rot(&(cam->vd), &(cam->vd), &(cam->rot_axis), (cam->rot_angle));
	ft_quater_rot(&(cam->vdr), &(cam->vdr), &(cam->rot_axis), (cam->rot_angle));
	ft_normalize_vector(&(cam->vd));
	ft_normalize_vector(&(cam->vdr));
	ft_quater_rot(&(cam->vdu), &(cam->vdr), &(cam->vd), ft_degree_to_rad(-90));
}

void	ft_init_cam(t_cam *cam)
{
	ft_init_cam_vectors(cam);
	cam->vp.width = 1.0;
	cam->vp.height = 1.0;
	cam->vp.dist = 1.0;
}
