/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:20:15 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/15 19:21:17 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_skip_until_relevant(const char *str, int i)
{
	while (str[i] != '\0' && str[i] != '-' && str[i] != '+'
			&& ft_isdigit(str[i]) == 0)
		i++;
	return (i);
}

static int		check_if_dud(const char *str, int i)
{
	while (str[i] != '\0' && str[i] != '-' && str[i] != '+'
		&& ft_isdigit(str[i]) == 0)
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\v' && str[i] != '\n'
				&& str[i] != '\r' && str[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}

static int		letsdothemath(const char *str, int start, int end, int sign)
{
	int				power;
	unsigned int	total;
	int				i;

	power = (end - start);
	i = start;
	total = 0;
	while (i <= end && power > 0)
	{
		total = total * 10 + ((str[i] - '0'));
		power--;
		i++;
	}
	if (sign < 0)
		total = total * -1;
	return ((int)total);
}

int				ft_atoi(const char *str)
{
	int	i;
	int	start;
	int	end;
	int sign;

	i = 0;
	sign = 1;
	if (check_if_dud(str, i) == 1)
		return (0);
	i = ft_skip_until_relevant(str, i);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	start = i;
	while (ft_isdigit(str[i]) == 1)
		i++;
	end = i;
	if (start == end && ft_isdigit(str[start]) == 0)
		return (0);
	return (letsdothemath(str, start, end, sign));
}
