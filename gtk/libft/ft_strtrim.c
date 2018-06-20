/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:18:58 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/15 19:51:34 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int		ft_get_end(char const *s, int i, int start)
{
	int end;

	while (s[i] != '\0')
		i++;
	i--;
	while (ft_is_space(s[i]) == 1 && start < i)
		i--;
	end = i;
	return (end);
}

char			*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*buff;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0' && ft_is_space(s[i]) == 1)
		i++;
	start = i;
	end = ft_get_end(s, i, start);
	buff = (char*)malloc(sizeof(*buff) * ((end - start) + 2));
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		buff[i] = s[start];
		start++;
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
