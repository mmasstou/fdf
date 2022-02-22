/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:51:56 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/20 18:51:59 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	ft_padding(t_fdf *map_data)
{
	float	x;
	float	y;

	x = cos(map_data->alpha) * (map_data->height * map_data->zom);
	y = cos(map_data->alpha) * (map_data->width * map_data->zom);
	map_data->pad_w = map_data->width - (x + y);
	map_data->pad_w /= 2;
	map_data->pad_w += x;
	x = sin(map_data->alpha) * map_data->width * map_data->zom;
	y = sin(map_data->alpha) * map_data->height * map_data->zom;
	map_data->pad_h = map_data->height - (x + y);
	map_data->pad_h /= 2;
	map_data->pad_h +=  fmax(x, y) / 2 ;
}
