/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_balise_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:06:57 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/08 16:28:15 by mfrisby          ###   ########.fr       */
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
	name = ft_strnew(len + 1);
	len = 0;
	while (s[len] != '>')
	{
		name[len] = s[len];
		len++;
	}
	name[len] = '\0';
	return (name);
}
