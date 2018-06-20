/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_primitives.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:22:12 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/20 20:16:45 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_plane_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char	*content;

	list = *prims;
	list = ft_add_lst_file(list, PLANE);
	*prims = list;
	last = ft_get_last(list);
	content = xmlp_get_child_node_content(node, "plane/origin");
	ft_set_3dpt_from_string(&(last->plane.point), content);
	content = xmlp_get_child_node_content(node, "plane/vec");
	ft_set_3dpt_from_string(&(last->plane.normal), content);
	ft_parse_color(node, &(last->color2), "plane");
	ft_parsing_mov(node, last, "plane");
	ft_count_options(last, node, "plane");
}

void	ft_cylinder_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char	*content;
	// int		i;

	list = *prims;
	list = ft_add_lst_file(list, CYLINDER);
	*prims = list;
	last = ft_get_last(list);
	content = xmlp_get_child_node_content(node, "cylinder/origin");
	ft_set_3dpt_from_string(&(last->cyl.origin), content);
	content = xmlp_get_child_node_content(node, "cylinder/vec");
	ft_set_3dpt_from_string(&(last->cyl.vec), content);
	content = xmlp_get_child_node_content(node, "cylinder/radius");
	if (content == NULL)
		ft_error("Need Radius for Cylinder");
	last->cyl.radius = ft_atoi(content);
	if (last->cyl.radius <= 0)
		ft_error("Radius can not be Null or negative");
	ft_parse_color(node, &(last->color2), "cylinder");
	ft_parsing_mov(node, last, "cylinder");
	ft_count_options(last, node, "cylinder");
	// i = (tab + 7, last);

}

void	ft_cone_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char	*content;
	// int		i;

	list = *prims;
	list = ft_add_lst_file(list, CONE);
	*prims = list;
	last = ft_get_last(list);
	content = xmlp_get_child_node_content(node, "cone/origin");
	ft_set_3dpt_from_string(&(last->cone.origin), content);

	content = xmlp_get_child_node_content(node, "cone/vec");
	ft_set_3dpt_from_string(&(last->cone.vec), content);
	content = xmlp_get_child_node_content(node, "cone/angle");
	if (content == NULL)
		ft_error("Need angle for Cone");
	last->cone.angle = ft_degree_to_rad(ft_atoi(content));
	if (last->cone.angle <= 0)
		ft_error("Angle can not be Null or negative");
	ft_parse_color(node, &(last->color2), "cone");
	ft_parsing_mov(node, last, "cone");
	ft_count_options(last, node, "cone");
	// i = read_cut(tab + 7, last);
}

void	ft_sphere_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char	*content;
	// int		i;

	content = NULL;
	list = *prims;
	list = ft_add_lst_file(list, SPHERE);
	*prims = list;
	last = ft_get_last(list);
	content = xmlp_get_child_node_content(node, "sphere/origin");
	ft_set_3dpt_from_string(&(last->sphere.origin), content);
	content = xmlp_get_child_node_content(node, "sphere/radius");
	if (content == NULL)
		ft_error("Need Radius for sphere");
	last->sphere.radius = ft_atoi(content);
	ft_parse_color(node, &(last->color2), "sphere");
	ft_parsing_mov(node, last, "sphere");
	// i = read_cut(tab + 6, last);
	ft_count_options(last, node, "sphere");
}
