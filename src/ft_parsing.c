/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:56:10 by kjalloul          #+#    #+#             */
/*   Updated: 2018/04/26 08:06:40 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_prim	*ft_get_last(t_prim *last)
{
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	ft_parsing_mov(char *rot, char *transl, t_prim *last, void (*err)(void))
{
	char **tmp;

	tmp = ft_strsplit(rot, ':');
	if (ft_count_tab(tmp) != 6 || ft_strequ(tmp[0], "rotation") == 0
										|| ft_strequ(tmp[4], "angle") == 0)
		err();
	ft_set_3dpt(&(last->rot_axis), (double)ft_atoi(tmp[1]),
				(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	last->rot_angle = ft_degree_to_rad((double)ft_atoi(tmp[5]));
	ft_free_tab(tmp);
	tmp = ft_strsplit(transl, ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "translation") == 0)
		err();
	ft_set_3dpt(&(last->transl), (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_free_tab(tmp);
}

void	ft_parse_color(char *color, t_color *color2, void (*ft_err)(void))
{
	char **tmp;

	tmp = ft_strsplit(color, ':');
	if (ft_count_tab(tmp) != 7 || ft_strequ(tmp[0], "color") == 0)
		ft_err();
	ft_set_color(color2, ft_atoi(tmp[2]), ft_atoi(tmp[4]), ft_atoi(tmp[6]));
	ft_free_tab(tmp);
}

void	ft_parsing_primitives(int fd, t_prim **list, t_light **spots)
{
	char *str;
	char **tab;

	str = NULL;
	while (get_next_line(fd, &str) > 0)
	{
		if (str == NULL)
			ft_error(ERROR);
		tab = ft_strsplit(str, '|');
		if (ft_count_tab(tab) > 0)
		{
			if (ft_strequ(tab[0], "plane") == 1)
				ft_plane_setup(tab, list);
			else if (ft_strequ(tab[0], "sphere") == 1)
				ft_sphere_setup(tab, list);
			else if (ft_strequ(tab[0], "cylinder") == 1)
				ft_cylinder_setup(tab, list);
			else if (ft_strequ(tab[0], "cone") == 1)
				ft_cone_setup(tab, list);
			else if (ft_strequ(tab[0], "spot") == 1)
				ft_spot_setup(tab, spots);
			else if (ft_strequ(tab[0], "ambiant") == 1)
				ft_ambiant_setup(tab, spots);
		}
		free(str);
		ft_free_tab(tab);
	}
}

void	ft_parsing_start(char *file, t_cam *cam, t_light **spot, t_prim **list)
{
	int		fd;
	char	*str;

	str = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error(ERRFILE);
	if (get_next_line(fd, &str) < 0)
		ft_error_cam();
	ft_check_camera(str, cam);
	free(str);
	ft_parsing_primitives(fd, list, spot);
}
