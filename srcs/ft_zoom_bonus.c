/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:46:52 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/25 11:55:53 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

void	ft_zoom_bonus(t_fdf *data, int _zoom, int _altitude)
{
	if (_altitude == 0 || _zoom == 0)
	{
		data->altitude = 1;
		if (data->width >= 100)
			data->zom = ((data->win_w / data->width) / 2) + 2;
		else
		{
			data->zom = (data->win_h / (data->height \
			* data->height) + data->height) + 22;
		}
	}
	else
	{
		data->altitude = _altitude;
		data->zom = _zoom;
	}
}
