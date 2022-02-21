/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:16:48 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 13:16:50 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	img_init(t_data_img *map_data)
{
	map_data->endian = 0;
	map_data->line_len = WIDTH * 4;
	map_data->bpp = 32;
	map_data->mlx = mlx_init();
}

int	pixel_init(t_fdf *fdf)
{
	fdf->pixel = (t_pixel *)malloc(sizeof(t_pixel));
	if (!fdf->pixel)
		return (-1);
	fdf->pixel->x1 = 0;
	fdf->pixel->y1 = 0;
	fdf->pixel->x2 = 0;
	fdf->pixel->y2 = 0;
	fdf->pixel->z = 0;
	fdf->pixel->z1 = 0;
	fdf->pixel->color = 0xffffff;
	return (0);
}

t_fdf	*data_init(void)
{
	t_fdf	*map_data;

	map_data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!map_data)
		return (NULL);
	map_data->img = (t_data_img *)malloc(sizeof(t_data_img));
	if (!map_data->img)
		return (NULL);
	map_data->pos_m = (t_mouse *)malloc(sizeof(t_mouse));
	if (!map_data->pos_m)
		return (NULL);
	if (pixel_init(map_data) == -1)
		return (NULL);
	map_data->alpha = 0.523599 ;
	map_data->beta = 0.523599 ;
	map_data->key = -1;
	map_data->colos_name = ft_strdup("Default");
	map_data->color_auto = true;
	return (map_data);
}
