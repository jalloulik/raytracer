/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:08:10 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/13 16:52:39 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dsti;
	size_t srci;

	i = 0;
	dsti = ft_strlen(dst);
	srci = ft_strlen(src);
	if ((dsti + 1) > size)
		return (srci + size);
	while (src[i] != '\0' && (dsti + 1) < size)
	{
		dst[dsti + i] = src[i];
		i++;
		size--;
	}
	dst[dsti + i] = '\0';
	if (src[i] == '\0')
		return (i + dsti);
	return (dsti + srci);
}
