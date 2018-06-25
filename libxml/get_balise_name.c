/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_balise_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:06:57 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/24 16:53:07 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libxml.h"

char		*get_balise_name(char *s)
{
	int		len;
	char	*name;

	len = 0;
	while (s[len] != '>')
		len++;
	if (!(name = (char*)malloc(sizeof(char) * (len + 1))))
		ft_error_2("probleme allocation memoire\n");
	len = 0;
	while (s[len] != '>')
	{
		name[len] = s[len];
		len++;
	}
	name[len] = '\0';
	return (name);
}
