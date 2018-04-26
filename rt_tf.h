/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 08:46:55 by tfavart           #+#    #+#             */
/*   Updated: 2018/04/26 13:30:46 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TF_H
# define RT_TF_H

# include "rtv1.h"
# define LIGHT 1
# define AMBIANT 2
# define SUN 3

void	ft_get_ambiant(t_prim *prim, t_ray *ray, t_light *light);
void	ft_ambiant_setup(char **tab, t_light **spots);
void	ft_sun_setup(char **tab, t_light **spots);
void	ft_check_ambiant(t_prim *small, t_light *light, t_ray *ray);
void	ft_check_sun(t_prim *list, t_prim *small, t_light *light, t_ray *ray);
void	ft_get_shade(t_prim *prim, t_ray *ray, t_light *light);
int		ft_check_obst(t_3dpt *o, t_3dpt *p_to_light, t_prim *obst, double dist);
void	ft_get_dotr(t_prim *small, t_light *light, t_3dpt *p, t_ray *ray);

#endif