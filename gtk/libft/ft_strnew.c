/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:17:05 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/15 18:39:47 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*buff;
	size_t	i;

	i = 0;
	buff = (char *)malloc(sizeof(*buff) * (size + 1));
	if (buff == NULL)
		return (NULL);
	while (i < (size + 1))
	{
		buff[i] = '\0';
		i++;
	}
	return (buff);
}
