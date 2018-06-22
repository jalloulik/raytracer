/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlp_get_child_node_content.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:38:26 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/22 15:05:04 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxml.h"
#include <stdlib.h>

char	**split_path(char *path, int *len)
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

char	*recursive_find(t_node *node, char **ps, int i, int len)
{
	char *content;

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
	return (content);
}

char		*xmlp_get_child_node_content(t_node *node, char *path)
{
	int		i;
	int		len;
	char	*ret;
	char	**ps;

	i = 0;
	len = 0;
	ps = split_path(path, &len);
	if (!ps)
		return (NULL);
	ret = recursive_find(node, ps, i, len);
	ft_free_tab(ps);
	return (ret);
}
