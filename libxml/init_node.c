/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:33:14 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/24 16:54:55 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxml.h"

t_node	*init_node(t_node *parent)
{
	t_node		*node;

	if(!(node = malloc(sizeof(t_node))))
		ft_error_2("probleme allocation memoire\n");
	node->parent = parent;
	node->next = NULL;
	node->child = NULL;
	node->content = NULL;
	node->name = NULL;
	return (node);
}
