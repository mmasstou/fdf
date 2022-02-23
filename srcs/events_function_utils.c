/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_function_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:06:46 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/23 16:06:48 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	event_rotation(int key, t_fdf *fdf)
{
	rotate_x(key, fdf);
	rotate_y(key, fdf);
	rotate_z(key, fdf);
}

void	rotate_x(int key, t_fdf *data)
{
	if (key == RO_X_UP)
	{
		data->alpha += 0.05;
		data->key = RO_X_UP;
	}
	if (key == RO_X_DOWN)
	{
		data->alpha -= 0.05;
		data->key = RO_X_DOWN ;
	}
}

void	rotate_y(int key, t_fdf *data)
{
	if (key == RO_Y_UP)
	{
		data->beta += 0.05;
		data->key = RO_Y_UP ;
	}
	if (key == RO_Y_DOWN)
	{
		data->beta -= 0.05;
		data->key = RO_Y_DOWN ;
	}
}

void	rotate_z(int key, t_fdf *data)
{
	if (key == RO_Z_UP)
	{
		data->gama += 0.05;
		data->key = RO_Z_UP ;
	}
	if (key == RO_Z_DOWN)
	{
		data->gama -= 0.05;
		data->key = RO_Z_DOWN ;
	}
}

void	defualt_projecton(t_fdf *fdf)
{
	fdf->projection->iso = true;
	fdf->projection->parallel = false;
	fdf->projection_name = ft_strdup("ISOMITRIC");
	fdf->alpha = 0 ;
	fdf->beta = 0 ;
	fdf->gama = 0 ;
	fdf->key = -1;
	fdf->colos_name = ft_strdup("Default");
	fdf->color_auto = true;
	fdf->pad_h = fdf->def->pad_h;
	fdf->pad_w = fdf->def->pad_w;
	fdf->zom = fdf->def->zoom;
	fdf->altitude = fdf->def->altitude;
}
