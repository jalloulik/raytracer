/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_primitives2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 11:10:38 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/19 11:37:22 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_cercle_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char *content;

	list = *prims;
	list = ft_add_lst_file(list, CERCLE);
	*prims = list;
	last = ft_get_last(list);

	content = xmlp_get_child_node_content(node, "cercle/origin");
	ft_set_3dpt_from_string(&(last->cercle.pos), content);

	content = xmlp_get_child_node_content(node, "cercle/vec");
	ft_set_3dpt_from_string(&(last->cercle.dir), content);
	ft_normalize_vector(&(last->cercle.dir));

	content = xmlp_get_child_node_content(node, "cercle/radius");
	if (content == NULL)
		ft_error("Need Radius for sphere");
	last->cercle.r = ft_atoi(content);
	ft_parse_color(node, &(last->color2), "cercle");
	ft_parsing_mov(node, last, "cercle");
}

void	ft_rectangle_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char *content;

	list = *prims;
	list = ft_add_lst_file(list, RECT);
	*prims = list;
	last = ft_get_last(list);
	content = xmlp_get_child_node_content(node, "rect/origin");
	ft_set_3dpt_from_string(&(last->rect.pos), content);
	content = xmlp_get_child_node_content(node, "rect/vec");
	ft_set_3dpt_from_string(&(last->rect.dir), content);
	ft_normalize_vector(&(last->rect.dir));
	content = xmlp_get_child_node_content(node, "rect/size/x");
	if (content == NULL)
		ft_error("Rectangle size needs a width");
	last->rect.width =  ft_atoi(content);
	content = xmlp_get_child_node_content(node, "rect/size/y");
	if (content == NULL)
		ft_error("Rectangle size needs a height");
	last->rect.height =  ft_atoi(content);
	ft_parse_color(node, &(last->color2), "rect");
	ft_parsing_mov(node, last, "rect");
}

void	ft_tore_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char *content;

	list = *prims;
	list = ft_add_lst_file(list, TORE);
	*prims = list;
	last = ft_get_last(list);

	content = xmlp_get_child_node_content(node, "tore/origin");
	ft_set_3dpt_from_string(&(last->tore.pos), content);

	content = xmlp_get_child_node_content(node, "tore/vec");
	ft_set_3dpt_from_string(&(last->tore.dir), content);
	ft_normalize_vector(&(last->tore.dir));
	content = xmlp_get_child_node_content(node, "tore/r1");
	last->tore.r1 =  ft_atoi(content);
	content = xmlp_get_child_node_content(node, "tore/r2");
	last->tore.r2 =  ft_atoi(content);
	ft_parse_color(node, &(last->color2), "tore");
	ft_parsing_mov(node, last, "tore");

}

void	ft_triangle_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char *content;

	list = *prims;
	list = ft_add_lst_file(list, TRIANGLE);
	*prims = list;
	last = ft_get_last(list);

	content = xmlp_get_child_node_content(node, "triangle/p1");
	ft_set_3dpt_from_string(&(last->triangle.p1), content);
	content = xmlp_get_child_node_content(node, "triangle/p2");
	ft_set_3dpt_from_string(&(last->triangle.p2), content);
	content = xmlp_get_child_node_content(node, "triangle/p3");
	ft_set_3dpt_from_string(&(last->triangle.p3), content);
	ft_parse_color(node, &(last->color2), "triangle");
	ft_parsing_mov(node, last, "triangle");
}
