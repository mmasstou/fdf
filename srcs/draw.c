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

static void	isomitric_fdf(float *x, float *y, float z, fdf *data)
{
	rotation(x, y, z, data);
	*x = (*x - *y) * cos(data->beta);
	*y = -z + (*x + *y) * sin(data->beta);
}

void	m_zoom(fdf *fdf)
{
	fdf->pixel->x2 *= fdf->zom;
	fdf->pixel->y2 *= fdf->zom;
	fdf->pixel->x1 *= fdf->zom;
	fdf->pixel->y1 *= fdf->zom;
	fdf->pixel->z *= fdf->altitude;
	fdf->pixel->z1 *= fdf->altitude;
	isomitric_fdf(&fdf->pixel->x1, &fdf->pixel->y1, fdf->pixel->z, fdf);
	isomitric_fdf(&fdf->pixel->x2, &fdf->pixel->y2, fdf->pixel->z1, fdf);
	fdf->pixel->x1 += fdf->pad_w;
	fdf->pixel->y1 += fdf->pad_h;
	fdf->pixel->x2 += fdf->pad_w;
	fdf->pixel->y2 += fdf->pad_h;
}

void	dda(fdf *fdf)
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

void	pixel_manage(int x, int y, fdf *fdf, char c)
{
	fdf->pixel->x1 = x;
	fdf->pixel->y1 = y;
	fdf->pixel->x2 = x;
	fdf->pixel->y2 = y;
	if (c == 'x')
		fdf->pixel->x2 = x + 1;
	if (c == 'y')
		fdf->pixel->y2 = y + 1;
	fdf->pixel->z = fdf->matrix[(int)y][(int)x].z;
	fdf->pixel->z1 = fdf->matrix[(int)fdf->pixel->y2][(int)fdf->pixel->x2].z;
	fdf->pixel->color = fdf->matrix[(int)y][(int)x].color;
}

void	draw_map(fdf *fdf)
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
