/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 08:46:55 by tfavart           #+#    #+#             */
/*   Updated: 2018/04/26 10:44:33 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TF_H
# define RT_TF_H

# include "rtv1.h"
# define LIGHT 1
# define AMBIANT 2
# define SUN 3

typedef struct		s_ambiant
{
	int				type;
	double			intensity;
}					t_ambiant;

void				ft_get_ambiant(t_prim *prim, t_ray *ray, t_light *light);
void				ft_ambiant_setup(char **tab, t_light **spots);

#endif