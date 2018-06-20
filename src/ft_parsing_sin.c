/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_sin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:52:20 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/20 18:06:31 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_check_sinx(t_prim *last, t_node *node, char *type)
{
	char *content;

	content = ft_get_content_mix_path(node, type, "/sinx/a");
	if (content)
	{
		if (ft_atoi(content) <= 0)
			ft_error("Value cannot be smaller or equal to zero");
		last->sin.x = ft_atoi(content);
		content = ft_get_content_mix_path(node, type, "/sinx/b");
		if (ft_atoi(content) <= 0)
			ft_error("Sin div cannot be smaller or equal to zero");
		last->sin.x_div = ft_atoi(content);
		last->sin.status = TRUE;
		last->sin.xstatus = TRUE;
	}
}

static void	ft_check_siny(t_prim *last, t_node *node, char *type)
{
	char *content;

	content = ft_get_content_mix_path(node, type, "/siny/a");
	if (content)
	{
		if (ft_atoi(content) <= 0)
			ft_error("Value cannot be smaller or equal to zero");
		last->sin.y = ft_atoi(content);
		content = ft_get_content_mix_path(node, type, "/siny/b");
		if (ft_atoi(content) <= 0)
			ft_error("Sin div cannot be smaller or equal to zero");
		last->sin.y_div = ft_atoi(content);
		last->sin.status = TRUE;
		last->sin.ystatus = TRUE;
	}
}

static void	ft_check_sinz(t_prim *last, t_node *node, char *type)
{
	char *content;

	content = ft_get_content_mix_path(node, type, "/sinz/a");
	if (content)
	{
		if (ft_atoi(content) <= 0)
			ft_error("Value cannot be smaller or equal to zero");
		last->sin.z = ft_atoi(content);
		content = ft_get_content_mix_path(node, type, "/sinz/b");
		if (ft_atoi(content) <= 0)
			ft_error("Sin div cannot be smaller or equal to zero");
		last->sin.z_div = ft_atoi(content);
		last->sin.status = TRUE;
		last->sin.zstatus = TRUE;
	}
}

void		ft_check_sin(t_prim *last, t_node *node, char *type)
{
	ft_check_sinx(last, node, type);
	ft_check_siny(last, node, type);
	ft_check_sinz(last, node, type);
}
