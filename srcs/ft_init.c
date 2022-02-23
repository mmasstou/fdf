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

static void	fdf_init_val(t_fdf *fdf)
{
	fdf->def->pad_h = 0;
	fdf->def->pad_w = 0;
	fdf->def->zoom = 0;
	fdf->projection->iso = true;
	fdf->projection->parallel = false;
	fdf->projection_name = ft_strdup("ISOMITRIC");
	fdf->alpha = 0 ;
	fdf->beta = 0 ;
	fdf->gama = 0 ;
	fdf->key = -1;
	fdf->colos_name = ft_strdup("Default");
	fdf->color_auto = true;
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
	map_data->projection = (t_proj *)malloc(sizeof(t_proj));
	if (!map_data->projection)
		return (NULL);
	map_data->def = (t_default *)malloc(sizeof(t_default));
	if (!map_data->def)
		return (NULL);
	if (pixel_init(map_data) == -1)
		return (NULL);
	fdf_init_val(map_data);
	return (map_data);
}

t_pnt	**map_init(t_fdf *fdf)
{
	int		i;

	i = 0;
	fdf->matrix = (t_pnt **)malloc(sizeof(t_pnt *) * (fdf->height + 1));
	if (!fdf->matrix)
	{
		ft_putstr_fd("Allocate error \n", STDERR_FILENO);
		fdf_free(fdf);
		exit(EXIT_FAILURE);
	}
	while (i < fdf->height)
	{
		fdf->matrix[i++] = (t_pnt *)malloc(sizeof(t_pnt) * (fdf->width + 1));
		if (!fdf->matrix)
		{
			ft_putstr_fd("Allocate error \n", STDERR_FILENO);
			fdf_free(fdf);
			exit(EXIT_FAILURE);
		}
	}
	return (fdf->matrix);
}
