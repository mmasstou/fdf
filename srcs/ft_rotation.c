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

void	rotate_x(int key, fdf *data)
{
	if (key == RO_X_UP)
	{
		data->alpha += 0.1;
		data->key = RO_X_UP;
	}
	if (key == RO_X_DOWN)
	{
		data->alpha -= 0.1;
		data->key = RO_X_DOWN ;
	}
}

void	rotate_y(int key, fdf *data)
{
	if (key == RO_Y_UP)
	{
		data->alpha += 0.1;
		data->key = RO_Y_UP ;
	}
	if (key == RO_Y_DOWN)
	{
		data->alpha -= 0.1;
		data->key = RO_Y_DOWN ;
	}
}

void	rotate_z(int key, fdf *data)
{
	if (key == RO_Z_UP)
	{
		data->alpha += 0.1;
		data->key = RO_Z_UP ;
	}
	if (key == RO_Z_DOWN)
	{
		data->alpha -= 0.1;
		data->key = RO_Z_DOWN ;
	}
}
