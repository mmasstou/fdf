/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:07:46 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 18:07:50 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	resolution(t_fdf *map_data)
{
	map_data->win_h = HEIGHT;
	map_data->win_h += (map_data->win_h * .15);
	map_data->win_h *= map_data->zom;
	map_data->win_w = WIDTH;
	map_data->win_w += (map_data->win_w * .15);
	map_data->win_w *= map_data->zom;
	if (map_data->win_w >= 2592)
	{
		map_data->win_w = 2592;
		map_data->zom -= 1.6;
	}
	if (map_data->win_h >= 1440)
	{
		map_data->win_h = 1440;
		map_data->zom -= 1.4;
	}
}
