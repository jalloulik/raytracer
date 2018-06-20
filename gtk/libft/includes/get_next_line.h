/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:55:26 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/04 09:09:21 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 2000

typedef struct	s_buff
{
	int				fd;
	char			*fullbuff;
	int				eof;
	int				err;
	struct s_buff	*next;
}				t_buff;

int				get_next_line(const int fd, char **line);

#endif
