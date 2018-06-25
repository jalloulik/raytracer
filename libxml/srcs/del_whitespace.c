/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_whitespace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:37:26 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/25 16:55:11 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxml.h"

void	ft_overwrite(char *result, char *source)
{
	int i;

	i = 0;
	if (source == NULL || result == NULL)
		return ;
	while (source[i] != 0)
	{
		result[i] = source[i];
		i++;
	}
	result[i] = '\0';
	free(source);
}

char	*dell_whitespace(char *str)
{
	char	*head;
	int		start;
	int		len;

	if (str == NULL)
		return (NULL);
	head = str;
	start = 0;
	len = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
	{
		start++;
		str++;
	}
	while (*str)
		str++;
	str--;
	while (*str == ' ' || *str == '\t' || *str == '\n')
	{
		len++;
		str--;
	}
	len = ft_strlen(head) - start - len;
	return (ft_strsub(head, start, len));
}
