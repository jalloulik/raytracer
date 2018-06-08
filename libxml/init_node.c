/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:33:14 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/08 16:28:25 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxml.h"

t_node	*init_node(t_node *parent)
{
	t_node		*node;

	node = malloc(sizeof(t_node));
	node->parent = parent;
	node->next = NULL;
	node->child = NULL;
	node->content = NULL;
	node->name = NULL;
	return (node);
}
