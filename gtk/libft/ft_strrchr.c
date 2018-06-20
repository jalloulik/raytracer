/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:39:42 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/09 14:43:09 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = 0;
	while (*s != '\0')
	{
		s++;
		len++;
	}
	while (len >= 0)
	{
		if (*s == c)
			return ((char*)s);
		s--;
		len--;
	}
	return (NULL);
}
