/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libxml.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:50:30 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/22 14:24:28 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBXML_H
# define LIBXML_H

# include "../../libft/includes/libft.h"

# define CLOSE 1
# define OPEN 2

typedef struct			s_xmlp
{
	int					fd;
	int					len;
	char				*path;
	char				*content;
	char				*status;
	struct s_node		*node;
}						t_xmlp;

typedef	struct			s_node
{
	char				*content;
	char				*name;
	struct s_node		*parent;
	struct s_node		*child;
	struct s_node		*next;
}						t_node;

t_xmlp					*new_xmlp(char *path);
t_node					*xmlp_get_next_node(t_xmlp *xmlp, char *path);
t_node					*xmlp_get_node(t_xmlp *xmlp, char *path);
char					*xmlp_get_child_node_content(t_node *node, char *path);
char					*xmlp_get_node_content(t_xmlp *xmlp, char *path);
char					**xmlp_split_node_content(t_xmlp *xmlp, char *path,
							char delimiter);
void					read_file(int fd, t_xmlp *xmlp);
int						open_file(char *path);
char					*get_const_balise(char *name, int is_open);
void					node_parser(t_xmlp *xmlp);
t_node					*init_node(t_node *parent);
char					*get_balise_name(char *s);
char					*get_balise_content(char *s, int i);
int						is_balise_closed(char *name, char *s);
void					ft_free_tab(char **tab);

#endif
