/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:35:21 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/13 10:26:03 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*srctmp;

	i = 0;
	tmp = dst;
	srctmp = (unsigned char *)src;
	while (i < n)
	{
		tmp[i] = srctmp[i];
		i++;
	}
	return (dst);
}
