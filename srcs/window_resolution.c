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
	map_data->win_w = 1920;
	map_data->win_h = 1080;
}

float	get_percent(int val, int perc)
{
	return ((val * perc) / 100);
}
