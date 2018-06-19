/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:51:18 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/15 18:33:35 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmplist;
	t_list *prev;

	if (alst == NULL)
		return ;
	tmplist = *alst;
	while (tmplist != NULL)
	{
		prev = tmplist;
		del(tmplist->content, tmplist->content_size);
		free(tmplist);
		if (prev != NULL)
			tmplist = prev->next;
	}
	*alst = NULL;
}
