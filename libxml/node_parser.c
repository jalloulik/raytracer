/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:02:09 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/15 18:47:17 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxml.h"
#include <stdlib.h>

static int		get_content(t_node **node, char *s, int i, int *len)
{
	if (!(*node))
	{
		ft_putendl("\033[31m Erreur content sans balise \033[0m");
		(*len) = 0;
		return (i);
	}
	(*node)->content = get_balise_content(s, i);
	while (s && s[i] && s[i] != '<')
		i++;
	return (i);
}

static int		balise_closed(t_node **node, char *s, int i, int *len)
{
	if ((is_balise_closed((*node)->name, s + i)) == 1)
	{
		while (s[i] != '>')
			i++;
		i++;
		(*node) = (*node)->parent;
	}
	else
	{
		ft_putendl("\033[31m Erreur balise fermante \033[0m");
		(*len) = 0;
	}
	return (i);
}

static int		balise_opened(t_node **node, char *s, int i)
{
	if ((*node) && !(*node)->child)
	{
		(*node)->child = init_node((*node));
		(*node) = (*node)->child;
	}
	else if ((*node) && (*node)->child)
	{
		(*node) = (*node)->child;
		while ((*node)->next)
			(*node) = (*node)->next;
		(*node)->next = init_node((*node)->parent);
		(*node) = (*node)->next;
	}
	(*node)->name = get_balise_name(s + i);
	while (s[i] != '>')
		i++;
	return (i + 1);
}

static int		get_node(t_node *node, char *s, int i, int len)
{
	while (s && s[i] && s[i] == ' ')
		i++;
	if (!s || i < 0 || !s[i] || i >= len)
		return (-1);
	if (s[i] == '<' && s[i + 1] && s[i + 1] == '/')
		i = balise_closed(&node, s, i + 2, &len);
	else if (s[i] == '<')
		i = balise_opened(&node, s, i + 1);
	else
		i = get_content(&node, s, i, &len);
	if (i < len)
		i = get_node(node, s, i, len);
	return (i);
}

void			node_parser(t_xmlp *xmlp)
{
	int			ret;

	xmlp->node = init_node(NULL);
	ret = get_node(xmlp->node, xmlp->content, 0, xmlp->len);
}
