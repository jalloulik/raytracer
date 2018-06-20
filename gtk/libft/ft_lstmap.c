/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:20:49 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/15 19:46:34 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *current;
	t_list *prev;
	t_list *start;

	current = NULL;
	prev = NULL;
	start = NULL;
	while (lst != NULL)
	{
		if ((current = (t_list*)malloc(sizeof(*current))) == NULL)
			return (NULL);
		current = f(lst);
		if (prev != NULL)
			prev->next = current;
		else
			start = current;
		lst = lst->next;
		prev = current;
	}
	return (start);
}
