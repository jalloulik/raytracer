/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 08:46:55 by tfavart           #+#    #+#             */
/*   Updated: 2018/04/26 14:44:50 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TF_H
# define RT_TF_H

# include "rtv1.h"
# define LIGHT 1
# define AMBIANT 2
# define SUN 3

void	ft_get_ambiant(t_prim *prim, t_color *color, t_light *light);
void	ft_ambiant_setup(char **tab, t_light **spots);
void	ft_sun_setup(char **tab, t_light **spots);

#endif
