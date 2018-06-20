/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:27:27 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/14 09:19:09 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmpsrc;
	unsigned char	*tmpdst;

	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	if (tmpsrc < tmpdst)
	{
		i = len;
		while (i > 0)
		{
			tmpdst[i - 1] = tmpsrc[i - 1];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
