/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlp_get_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:38:41 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/22 15:07:04 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxml.h"
#include <stdlib.h>

static char		**split_path(char *path, int *len)
{
	char		**split;

	if (!path)
		return (NULL);
	split = ft_strsplit(path, '/');
	while (split[(*len)])
		(*len)++;
	(*len)--;
	return (split);
}

static t_node	*recursive_find(t_node *node, char **ps, int i, int len)
{
	t_node		*ret;

	ret = NULL;
	while (node)
	{
		if (node && ps && ps[i] && i != len && (ft_strcmp(node->name,
			ps[i])) == 0)
			ret = recursive_find(node->child, ps, i + 1, len);
		if (ret)
			return (ret);
		if (i == len && node && ps && ps[i] && (ft_strcmp(node->name,
			ps[i])) == 0)
			return (node);
		node = node->next;
	}
	return (ret);
}

t_node			*xmlp_get_node(t_xmlp *xmlp, char *path)
{
	int			i;
	int			len;
	char		**ps;
	t_node		*node;

	i = 0;
	len = 0;
	ps = split_path(path, &len);
	if (!ps)
		return (NULL);
	node = recursive_find(xmlp->node->child, ps, i, len);
	ft_free_tab(ps);
	return (node);
}
