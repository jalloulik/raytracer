/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlp_get_next_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:38:19 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/15 18:44:27 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxml.h"

t_node			*xmlp_get_next_node(t_xmlp *xmlp, char *path)
{
	static int	end = 0;
	int			i;
	char		*name;
	t_node		*node;

	i = -1;
	node = xmlp_get_node(xmlp, path);
	name = node->name;
	while (node)
	{
		if ((ft_strcmp(node->name, name)) == 0)
		{
			i++;
			if (i == end)
			{
				end++;
				return (node);
			}
		}
		node = node->next;
	}
	return (NULL);
}
