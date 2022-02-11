#include "../incs/fdf.h"

int ft_color(float z, float z1)
{
	if (z || z1)
		return (0xffffff);
	else
		return(0xffffff);
}

void	ft_drawline(fdf *map, int x, int y, int color)
{
	char	*dst;

	if((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		dst = map->img->img_addr + (y * map->img->line_len + x * (map->img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	dda(float x1, float y1, float x2, float y2, fdf *fdf)
{
	float	dx;
	float	dy;

	int		max;
	int		color;
	float		z;
	float		z1;

	color = fdf->matrix[(int)y1][(int)x1].color;
	z = fdf->matrix[(int)y1][(int)x1].z;
	z1 = fdf->matrix[(int)y2][(int)x2].z;
	
	if (color == -1)
		color = ft_color(z, z1);

	x1 *= fdf->zom;
	y1 *= fdf->zom;
	x2 *= fdf->zom;
	y2 *= fdf->zom;


	ft_trid(&x1, &y1, z, fdf);
	ft_trid(&x2, &y2, z1, fdf);
	
	x1 += fdf->pad_w;
	y1 += fdf->pad_h;
	x2 += fdf->pad_w;
	y2 += fdf->pad_h;

	dx = x2 - x1;
	dy = y2 - y1;

	max = MAX(ABS(dx), ABS(dy));
	dx /= max;
	dy /= max;
	
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		ft_drawline(fdf, x1, y1, color);
		x1 += dx;
		y1 += dy;
	}
}




void	ft_trid(float *x, float *y, int z, fdf *data)
{
	*x = (*x - *y) * cos(data->alpha);
	*y = (*x + *y) * sin(data->alpha) - ( data->altitude *  z);
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
				dda(x, y, x + 1, y, fdf);
			if (y < fdf->height - 1)
				dda(x, y, x, y + 1, fdf);
			y++;
		}
		x++;
	}
}

