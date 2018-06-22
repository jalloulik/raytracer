/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlp_get_node_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:40:10 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/22 14:23:23 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxml.h"
#include <stdlib.h>

static char	**split_path(char *path, int *len)
{
	char	**split;

	if (!path)
		return (NULL);
	split = ft_strsplit(path, '/');
	while (split[(*len)])
		(*len)++;
	(*len)--;
	return (split);
}

static char	*recursive_find(t_node *node, char **ps, int i, int len)
{
	char	*content;

	content = NULL;
	while (node)
	{
		if (node && ps && ps[i] && i != len && (ft_strcmp(node->name,
			ps[i])) == 0)
			content = recursive_find(node->child, ps, i + 1, len);
		if (content)
			return (content);
		if (i == len && node && ps && ps[i] && (ft_strcmp(node->name,
			ps[i])) == 0)
			return (node->content);
		node = node->next;
	}
	ft_free_tab(ps);
	return (content);
}

char		*xmlp_get_node_content(t_xmlp *xmlp, char *path)
{
	int		i;
	int		len;
	char	**ps;
	t_node	*node;

	i = 0;
	len = 0;
	ps = split_path(path, &len);
	if (!ps)
		return (NULL);
	node = xmlp->node->child;
	return (recursive_find(node, ps, i, len));
}
