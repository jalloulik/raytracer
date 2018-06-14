/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:46:36 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/09 17:08:04 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *tmp;

	tmp = (unsigned char*)b;
	while (len > 0)
	{
		(*tmp) = (unsigned char)c;
		tmp++;
		len--;
	}
	return (b);
}
