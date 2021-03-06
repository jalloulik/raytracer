/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 08:46:55 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/19 02:18:08 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TF_H
# define RT_TF_H

# include "rtv1.h"
# define LIGHT 1
# define AMBIANT 2
# define SUN 3

void	ft_get_ambiant(t_prim *prim, t_color *color, t_light *light);
void	ft_ambiant_setup(t_node *node, t_light **spots);
void	ft_sun_setup(t_node *node, t_light **spots);
double	ft_test_smallest(t_light *light, t_prim *prim);
void	ft_resolve_light(t_light *light, t_3dpt *ray, t_3dpt *origin);

#endif
