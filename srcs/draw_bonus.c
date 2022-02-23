/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:36:47 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 12:36:50 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	fdf_iso(float *x, float *y, int *z)
{
	float	pre_x;
	float	pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = (pre_x - pre_y) * cos(0.523599);
	*y = -*z + (pre_x + pre_y) * sin(0.523599);
}

static void	isomitric_fdf(float *x, float *y, int *z, t_fdf *data)
{
	rotation_x(y, z, data->alpha);
	rotation_y(x, z, data->beta);
	rotation_z(x, y, data->gama);
	if (data->projection->iso == true || data->key == 48)
		fdf_iso(x, y, z);
}

static void	m_zoom(t_fdf *fdf)
{
	fdf->pixel->x2 *= fdf->zom;
	fdf->pixel->y2 *= fdf->zom;
	fdf->pixel->x1 *= fdf->zom;
	fdf->pixel->y1 *= fdf->zom;
	fdf->pixel->z *= ((fdf->zom / 5) * fdf->altitude);
	fdf->pixel->z1 *= ((fdf->zom / 5) * fdf->altitude);
	fdf->pixel->x2 -= (fdf->width * fdf->zom) / 2;
	fdf->pixel->y2 -= (fdf->height * fdf->zom) / 2;
	fdf->pixel->x1 -= (fdf->width * fdf->zom) / 2;
	fdf->pixel->y1 -= (fdf->height * fdf->zom) / 2;
	isomitric_fdf(&fdf->pixel->x1, &fdf->pixel->y1, &fdf->pixel->z, fdf);
	isomitric_fdf(&fdf->pixel->x2, &fdf->pixel->y2, &fdf->pixel->z1, fdf);
	fdf->pixel->x1 += fdf->pad_w;
	fdf->pixel->y1 += fdf->pad_h;
	fdf->pixel->x2 += fdf->pad_w;
	fdf->pixel->y2 += fdf->pad_h;
}

static void	dda(t_fdf *fdf)
{
	float	d[2];
	int		color;
	int		max;

	color = fdf->pixel->color;
	if (color == -1 || color == 0xffffff)
		color = ft_color(fdf->pixel->z, fdf->pixel->z1, fdf);
	m_zoom(fdf);
	d[0] = fdf->pixel->x2 - fdf->pixel->x1;
	d[1] = fdf->pixel->y2 - fdf->pixel->y1;
	max = fmax(fabs(d[0]), fabs(d[1]));
	d[0] /= max;
	d[1] /= max;
	while ((int)(fdf->pixel->x1 - fdf->pixel->x2) || \
	(int)(fdf->pixel->y1 - fdf->pixel->y2))
	{
		ft_drawline(fdf, fdf->pixel->x1, fdf->pixel->y1, color);
		fdf->pixel->x1 += d[0];
		fdf->pixel->y1 += d[1];
	}
}

void	draw_map_bonus(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	while (x < fdf->width)
	{
		y = 0;
		while (y < fdf->height)
		{
			if (x < fdf->width - 1)
			{
				pixel_manage(x, y, fdf, 'x');
				dda(fdf);
			}
			if (y < fdf->height - 1)
			{
				pixel_manage(x, y, fdf, 'y');
				dda(fdf);
			}
			y++;
		}
		x++;
	}
}
