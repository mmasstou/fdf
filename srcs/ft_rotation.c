/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:58:52 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 09:58:55 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

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

// void	rotation(float *x, float *y, float z, t_fdf *data)
// {
// 	if (data->key == RO_X_UP || data->key == RO_X_DOWN)
// 	{
// 		z = -*y * sin(data->alpha) + z * cos(data->alpha);
// 		*y = *y * cos(data->alpha) + z * sin(data->alpha);
// 	}
// 	else if (data->key == RO_Y_UP || data->key == RO_Y_DOWN)
// 	{
// 		z = -*x * sin(data->alpha) + z * cos(data->alpha);
// 		*x = *x * cos(data->alpha) + z * sin(data->alpha);
// 	}
// 	else if (data->key == RO_Z_UP || data->key == RO_Z_DOWN)
// 	{
// 		*x = *x * cos(data->alpha) + *y * sin(data->alpha);
// 		*y = *y * cos(data->alpha) + *x * sin(data->alpha);
// 	}
// }
