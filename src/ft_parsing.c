/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:56:10 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/19 03:18:04 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rt_tf.h"

t_prim *ft_get_last(t_prim *last)
{
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void		ft_parsing_mov(t_node *node, t_prim *last, char *type)
{
	char *tmp;
	char *content;

	content = NULL;
	tmp = ft_strjoin(type, "/rotation/axis");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);

	if (content)
		ft_set_3dpt_from_string(&(last->rot_axis), content);
	tmp = ft_strjoin(type, "/rotation/angle");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (content)
		last->rot_angle = ft_degree_to_rad((double)ft_atoi(content));
	tmp = ft_strjoin(type, "/translation");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (content)
		ft_set_3dpt_from_string(&(last->transl), content);
}

void		ft_parse_color(char *color, t_color *color2, void (*ft_err)(void))
{
	char **tmp;

	tmp = ft_strsplit(color, ':');
	if (ft_count_tab(tmp) != 3)
	{
		ft_putendl("fuck");
		ft_err();
	}
	ft_set_color(color2, ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	ft_free_tab(tmp);
}

void		ft_parsing_start(char *file, t_cam *cam, t_light **spot, t_prim **list)
{
	char	*str;
	t_xmlp	*xmlp;
	t_node	*node;

	str = NULL;
	xmlp = new_xmlp(file);
	node = NULL;
	cam->status = FALSE;
	while ((node = xmlp_get_next_node(xmlp, "scene/cam")))
	{
		if (node && cam->status == FALSE)
			ft_check_camera(node, cam);
	}
	if (cam->status == FALSE)
		ft_error_cam();
	while ((node = xmlp_get_next_node(xmlp, "scene/spot")))
		ft_spot_setup(node, spot);
	while ((node = xmlp_get_next_node(xmlp, "scene/ambiant")))
		ft_ambiant_setup(node, spot);
	while ((node = xmlp_get_next_node(xmlp, "scene/sun")))
		ft_sun_setup(node, spot);
	while ((node = xmlp_get_next_node(xmlp, "scene/sphere")))
		ft_sphere_setup(node, list);
	while ((node = xmlp_get_next_node(xmlp, "scene/plane")))
		ft_plane_setup(node, list);
	while ((node = xmlp_get_next_node(xmlp, "scene/cylinder")))
		ft_cylinder_setup(node, list);
	while ((node = xmlp_get_next_node(xmlp, "scene/cone")))
		ft_cone_setup(node, list);
	while ((node = xmlp_get_next_node(xmlp, "scene/cercle")))
		ft_cercle_setup(node, list);
	while ((node = xmlp_get_next_node(xmlp, "scene/rect")))
		ft_rectangle_setup(node, list);
	while ((node = xmlp_get_next_node(xmlp, "scene/tore")))
		ft_tore_setup(node, list);
	while ((node = xmlp_get_next_node(xmlp, "scene/triangle")))
		ft_triangle_setup(node, list);
}
