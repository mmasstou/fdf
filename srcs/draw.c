#include "../incs/fdf.h"

int clo(float z, float z1)
{
	if (z || z1)
		return (0xe80c0c);
	else
		return(0xffffff);
}
void	dda(float x1, float y1, float x2, float y2, fdf *fdf)
{
	float	dx;
	float	dy;
	float	o;
	int		max;
	int		color;
	float		z;
	float		z1;


	o = 1.085;
	color = fdf->matrix[(int)y1][(int)x1].color;
	z = fdf->matrix[(int)y1][(int)x1].z;
	z1 = fdf->matrix[(int)y2][(int)x2].z;
	
	if (color == -1)
		color = 0xffffff;

	// if (color == -1)
	// 	color = clo(z1);

	x1 *= fdf->zom;
	y1 *= fdf->zom;
	x2 *= fdf->zom;
	y2 *= fdf->zom;


	x1 = (x1 - y1) * cos(o); 
	y1 = (x1 + y1) * sin(o) - z;  
	x2 = (x2 - y2) * cos(o); 
	y2 = (x2 + y2) * sin(o) - z1; 

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
		printf("%f -- %f\n",x1,y1);
		mlx_pixel_put(fdf->img->mlx, fdf->img->win, x1, y1, color);
		x1 += dx;
		y1 += dy;
	}
}

void	draw_map(fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				dda(x, y, x + 1, y, fdf);
			if (y < fdf->height - 1)
				dda(x, y, x, y + 1, fdf);
			x++;
		}
		y++;
	}
}
