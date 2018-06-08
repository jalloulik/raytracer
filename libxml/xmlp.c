/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:14:18 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/08 16:28:29 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxml.h"

t_xmlp		*new_xmlp(char *path)
{
	int		fd;
	t_xmlp	*xmlp;

	fd = open_file(path);
	if (fd < 0)
		return (NULL);
	xmlp = malloc(sizeof(t_xmlp));
	xmlp->fd = fd;
	xmlp->path = path;
	read_file(xmlp->fd, xmlp);
	close(xmlp->fd);
	if (!xmlp || !xmlp->content || xmlp->len <= 0)
	{
		free(xmlp);
		return (NULL);
	}
	node_parser(xmlp);
	return (xmlp);
}
