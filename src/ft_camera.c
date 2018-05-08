/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:40:09 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/08 09:41:07 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		ft_cam_mov(char *rot, char *transl, t_cam *cam)
{
	char **tmp;

	tmp = ft_strsplit(rot, ':');
	if (ft_count_tab(tmp) != 6 || ft_strequ(tmp[0], "rotation") == 0
										|| ft_strequ(tmp[4], "angle") == 0)
		ft_error_cam();
	ft_set_3dpt(&(cam->rot_axis), (double)ft_atoi(tmp[1]),
				(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	cam->rot_angle = ft_degree_to_rad((double)ft_atoi(tmp[5]));
	ft_free_tab(tmp);
	tmp = ft_strsplit(transl, ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "translation") == 0)
		ft_error_cam();
	ft_set_3dpt(&(cam->transl), (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_free_tab(tmp);
}

static void		ft_init_cam_vec(char **tab, t_cam *cam)
{
	ft_set_3dpt(&(cam->vd), 0, 0, -1);
	ft_set_3dpt(&(cam->vdr), 1, 0, 0);
	ft_cam_mov(tab[2], tab[3], cam);
}

void	ft_check_sepia(char *tab, t_cam *cam)
{
	char **tmp;

	tmp = ft_strsplit(tab, ':');
	if (ft_count_tab(tmp) != 2 || ft_strequ(tmp[0], "sepia") == 0)
		ft_error_cam();
	if (ft_strequ(tmp[1], "true") == 1)
		cam->sepia = TRUE;
	else if (ft_strequ(tmp[1], "false") == 1)
		cam->sepia = FALSE;
	else
		ft_error_cam();
}

static void		ft_camera_setup(char **tab, t_cam *cam)
{
	char **tmp;

	if (ft_strequ(tab[0], "cam") == 0)
		ft_error_cam();
	tmp = ft_strsplit(tab[1], ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "origin") == 0)
		ft_error_cam();
	ft_set_3dpt(&(cam->origin), (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_free_tab(tmp);
	ft_init_cam_vec(tab, cam);
	ft_free_tab(tab);
	ft_init_cam(cam);
	ft_check_sepia(tab[4], cam);
}

void			ft_check_camera(char *str, t_cam *cam)
{
	char **tab;

	if (str == NULL)
		ft_error_cam();
	tab = ft_strsplit(str, '|');
	if (tab == NULL)
		ft_error_cam();
	if (ft_count_tab(tab) != 5)
		ft_error_cam();
	ft_camera_setup(tab, cam);
}
