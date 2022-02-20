#include "../incs/fdf.h"

int ft_color(float z, float z1 ,fdf *fdf)
{
	int color;
	(void)fdf;
	
	if (fdf->key == RANDOM_COLORS)
		color = 0xFFFFFF  * fabsf( fdf->zom / fdf->altitude);
	else if (fdf->key == DEFAULT_COLORS)
		color = 0xFFFFFF;
	else 
		color = 0xFFFFFF;


	if (z || z1)
		return(color);
	else
		return(color);
}
int ft_close(int key, fdf *param)
{
	if (key == 53)
    {
		mlx_destroy_window(param->img->mlx, param->img->win);
		exit(0);
	}
	return (0);
}
void	ft_drawline(fdf *map, int x, int y, int color)
{
	char	*dst;

	if((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		dst = map->img->img_addr + ( y * map->img->line_len + x * (map->img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static void isomitric_fdf(float *x, float *y, float z , fdf *data)
{
	if (data->key == RO_X_UP || data->key == RO_X_DOWN)
	{
		z = -*y * sin(data->alpha) + z * cos(data->alpha);
		*y = *y * cos(data->alpha) + z * sin(data->alpha);
	}
	else if (data->key == RO_Y_UP || data->key == RO_Y_DOWN)
	{
		z = -*x * sin(data->alpha) + z * cos(data->alpha);
		*x = *x * cos(data->alpha) + z * sin(data->alpha);
	}
	else if (data->key == RO_Z_UP || data->key == RO_Z_DOWN)
	{
		*x = *x * cos(data->alpha) + *y * sin(data->alpha);
		*y = *y * cos(data->alpha) + *x * sin(data->alpha);
	}
    *x = (*x - *y) * cos(data->beta);
    *y = -z + (*x + *y) * sin(data->beta);
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
	
	if (color == -1 || color == 0xffffff)
		color = ft_color(z, z1,fdf);
	x1 *= fdf->zom;
	y1 *= fdf->zom;
	x2 *= fdf->zom;
	y2 *= fdf->zom;




	z *= fdf->altitude;
	z1 *= fdf->altitude;
	isomitric_fdf(&x1, &y1, z, fdf);
	isomitric_fdf(&x2, &y2, z1, fdf);

	x1 += fdf->pad_w;
	y1 += fdf->pad_h;
	x2 += fdf->pad_w;
	y2 += fdf->pad_h;
	dx = x2 - x1;
	dy = y2 - y1;

	max = fmax(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		ft_drawline(fdf, x1, y1, color);
		x1 += dx;
		y1 += dy;
	}
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

