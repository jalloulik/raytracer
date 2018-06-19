/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlp_get_next_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:38:19 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/19 02:27:19 by kjalloul         ###   ########.fr       */
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
	if (node)
		name = node->name;
	while (node)
	{
		if ((ft_strequ(node->name, name)) == 1)
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
	end = 0;
	return (NULL);
}
