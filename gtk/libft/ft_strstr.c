/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:47:02 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/08 19:15:31 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int terminator;

	i = 0;
	j = 0;
	terminator = 0;
	while (haystack[j] != '\0' && needle[i] != '\0')
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
