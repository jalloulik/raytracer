/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:34:22 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/10 18:31:18 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		terminator;

	i = 0;
	j = 0;
	terminator = 0;
	while (haystack[j] != '\0' && needle[i] != '\0' && j < len)
	{
		if (needle[i] == haystack[j])
		{
			i++;
			j++;
		}
		else
		{
			i = 0;
			terminator++;
			j = terminator;
		}
	}
	if (needle[i] == '\0')
		return ((char*)&(haystack[terminator]));
	else
		return (NULL);
}
