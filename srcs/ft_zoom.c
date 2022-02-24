/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:46:52 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/20 18:46:54 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	ft_zoom(t_fdf *data, int _altitude, int _zoom)
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
