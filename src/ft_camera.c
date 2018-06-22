/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:40:09 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/21 15:08:29 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		ft_cam_mov(t_node *node, t_cam *cam)
{
	char *str;

	str = NULL;
	str = xmlp_get_child_node_content(node, "cam/rotation/axis");
	if (str)
		ft_set_3dpt_from_string(&(cam->rot_axis), str);
	str = xmlp_get_child_node_content(node, "cam/rotation/angle");
	if (str)
		cam->rot_angle = ft_degree_to_rad((double)ft_atoi(str));
	str = xmlp_get_child_node_content(node, "cam/translation");
	if (str)
		ft_set_3dpt_from_string(&(cam->transl), str);
}

static void		ft_init_cam_vec(t_cam *cam)
{
	ft_set_3dpt(&(cam->vd), 0, 0, -1);
	ft_set_3dpt(&(cam->vdr), 1, 0, 0);
}

void			ft_check_sepia(t_node *node, t_cam *cam)
{
	char *str;

	str = xmlp_get_child_node_content(node, "cam/sepia");
	if (ft_strequ(str, "true") == 1)
		cam->sepia = TRUE;
	else
		cam->sepia = FALSE;
}

static void		ft_camera_setup(t_node *node, t_cam *cam)
{
	ft_init_cam_vec(cam);
	ft_cam_mov(node, cam);
	ft_init_cam(cam);
	ft_check_sepia(node, cam);
	cam->status = TRUE;
}

void			ft_check_camera(t_node *node, t_cam *cam)
{
	char *str;

	str = NULL;
	str = xmlp_get_child_node_content(node, "cam/origin");
	if (str == NULL)
		ft_error("Camera needs origin");
	ft_set_3dpt_from_string(&(cam->origin), str);
	ft_camera_setup(node, cam);
}
