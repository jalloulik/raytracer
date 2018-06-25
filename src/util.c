/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:30:44 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/25 16:25:49 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	revers_tab(double t[4])
{
	double tmp;

	tmp = t[3];
	t[3] = t[0];
	t[0] = tmp;
	tmp = t[2];
	t[2] = t[1];
	t[1] = tmp;
}

char	*dell_whitespace(char *str)
{
	char	*head;
	int		start;
	int		len;

	head = str;
	start = 0;
	len = 0;
	while (*str == ' ')
	{
		start++;
		str++;
	}
	while (*str)
		str++;
	str--;
	while (*str == ' ')
	{
		len++;
		str--;
	}
	len = ft_strlen(head) - start - len;
	return (ft_strsub(head, start, len));
}
