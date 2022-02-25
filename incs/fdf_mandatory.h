/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mandatory.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:29:56 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/25 12:45:11 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MANDATORY_H
# define FDF_MANDATORY_H

# include "fdf.h"

void	draw_map(t_fdf *fdf);
void	ft_zoom(t_fdf *fdf, int _altitude, int _zoom);
void	padding(t_fdf *fdf);
#endif
