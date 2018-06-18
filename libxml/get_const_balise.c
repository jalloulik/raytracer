/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_const_balise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:52:09 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/08 16:28:23 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libxml.h"

/*
** Retourne le nom de la balise
** boleen open/close balise type
** entoure des <> </>
** <nom> ou </nom>
*/

static int		copy(char *name, char **string, int y)
{
	int			i;

	i = 0;
	while (name[i])
	{
		(*string)[y] = name[i];
		i++;
		y++;
	}
	return (y);
}

char			*get_const_balise(char *name, int is_open)
{
	int			i;
	char		*string;

	i = 0;
	string = malloc(sizeof(name + 3));
	if (is_open >= 0)
	{
		string[0] = '<';
		i = 1;
	}
	else if (is_open < 0)
	{
		string[0] = '<';
		string[1] = '/';
		i = 2;
	}
	i = copy(name, &string, i);
	string[i] = '>';
	string[i + 1] = '\0';
	return (string);
}
