/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 20:11:13 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/20 20:11:27 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char	*ft_get_content_mix_path(t_node *node, char *type, char *path)
{
	char *tmp;
	char *content;

	tmp = ft_strjoin(type, path);
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	return (content);
}

void	ft_set_3dpt_from_string(t_3dpt *point, char *str)
{
	char	**tmp;

	if (str == NULL)
		ft_error("No coordinates");
	tmp = ft_strsplit(str, ':');
	if (ft_count_tab(tmp) != 3)
		ft_error("Point or vector coordinates should be formated x:y:z");
	ft_set_3dpt(point, (double)ft_atoi(tmp[0]), (double)ft_atoi(tmp[1]),
													(double)ft_atoi(tmp[2]));
	ft_free_tab(tmp);
}
