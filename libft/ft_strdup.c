/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:58:21 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/01 14:56:39 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buff;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	buff = malloc(sizeof(*buff) * ft_strlen(s1) + 1);
	if (buff == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		buff[i] = s1[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
