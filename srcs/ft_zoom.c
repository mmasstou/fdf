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

void	ft_zoom(fdf *data, int _altitude, int _zoom)
{
	if (_altitude == 0 || _zoom == 0)
	{
		data->altitude = 1;
		if (data->width >= 100)
			data->zom = ((WIDTH / data->width) / 2) + 3;
		else
		{
			data->zom = (HEIGHT / (data->height \
			* data->height) + data->height) + 26;
		}
	}
	else
	{
		data->altitude = _altitude;
		data->zom = _zoom;
	}
}
