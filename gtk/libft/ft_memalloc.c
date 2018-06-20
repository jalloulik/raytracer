/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:05:43 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/15 19:50:21 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*buff;
	size_t	i;

	i = 0;
	buff = (char*)malloc(size);
	if (buff == NULL)
		return (NULL);
	while (i < size)
	{
		buff[i] = 0;
		i++;
	}
	return ((void*)buff);
}
