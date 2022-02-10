#include "../incs/fdf.h"

int clo(float z, float z1)
{
	if (z || z1)
		return (0xffffff);
	else
		return(0xffffff);
}

void	custom_mlx_pixel_put(fdf *map, int x, int y, int color)
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
	int			retation;

	retation = 295;
	color = fdf->matrix[(int)y1][(int)x1].color;
	//printf("%d\n",color);
	z = fdf->matrix[(int)y1][(int)x1].z;
	z1 = fdf->matrix[(int)y2][(int)x2].z;
	
	if (color == -1)
		color = clo(z, z1);

	// if (color == -1)
	// 	color = clo(z1);

	x1 *= fdf->zom;
	y1 *= fdf->zom;
	x2 *= fdf->zom;
	y2 *= fdf->zom;


	x1 = (x1 - y1) * cos(ALPHA); 
	y1 = (x1 + y1) * sin(BETA) -( ALTITUDE *  z) ; 


	x2 = (x2 - y2) * cos(ALPHA); 
	y2 = (x2 + y2) * sin(BETA) - ( ALTITUDE * z1); 


	

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
		//printf("%f -- %f\n",x1,y1);
		custom_mlx_pixel_put(fdf, x1, y1, color);
		//mlx_pixel_put(fdf->img->mlx, fdf->img->win, x1, y1, color);
		x1 += dx;
		y1 += dy;
	}
}




// void	ft_trid(int *x, int *y, int z)
// {
// 	*x = (*x - *y) * cos(0.8);
// 	*y = (*x + *y) * sin(0.8) - z;
// }

// void	prep_xy(int *x, int *y, int *x1, int *y1, int *z, int *z1, fdf *fdf)
// {
// 	*z = fdf->matrix[*y][*x].z;
// 	*z1 = fdf->matrix[*y1][*x1].z;
// 	*x *= fdf->zom;
// 	*y *= fdf->zom;
// 	*x1 *= fdf->zom;
// 	*y1 *= fdf->zom;

// 	ft_trid(x, y, *z);
// 	ft_trid(x1, y1, *z1);
// 	x += fdf->win_w;
// 	y += fdf->win_h;
// 	x1 += fdf->win_w;
// 	y1 += fdf->win_h;
// }

// void	bresenham(int x1, int y1, int x2, int y2, fdf *fdf)
// {
// 	int		dx;
// 	int		dy;
// 	int		P;
// 	int		y_step;
// 	int		z;
// 	int		z1;
// 	char	steep;
// 	int		color;
// 	float		o;
// 	float		r;

// 	o = 0.9;
// 	r = 0.8;
// 	color = fdf->matrix[(int)y1][(int)x1].color;
// 	z = fdf->matrix[(int)y1][(int)x1].z;
// 	z1 = fdf->matrix[(int)y2][(int)x2].z;
	
// 	if (color == -1)
// 		color = clo(z, z1);

// 	x1 *= fdf->zom;
// 	y1 *= fdf->zom;
// 	x2 *= fdf->zom;
// 	y2 *= fdf->zom;


// 	x1 = (x1 - y1) * cos(o); 
// 	y1 = (x1 + y1) * sin(r) - (z * 1.2); 
	
	 
// 	x2 = (x2 - y2) * cos(o); 
// 	y2 = (x2 + y2) * sin(r) - (z1 * 1.2); 

// 	x1 += fdf->pad_w;
// 	y1 += fdf->pad_h;
// 	x2 += fdf->pad_w;
// 	y2 += fdf->pad_h;



// 	dx = ABS(x2 - x1);
// 	dy = ABS(y2 - y1);


// 	steep = dy > dx;
// 	if (steep)
// 	{
// 		ft_swap(&x1, &y1);
// 		ft_swap(&x2, &y2);
// 		dx = ABS(x2 - x1);
// 		dy = ABS(y2 - y1);
// 	}
// 	if (x1 > x2)
// 	{
// 		ft_swap(&x1, &x2);
// 		ft_swap(&y1, &y2);
// 	}
// 	y_step = y2 > y1 ? 1 : -1;
// 	P = 2 * dy - dx;
// 	while (x1 <= x2)
// 	{
// 		if (steep)
// 			mlx_pixel_put(fdf->img->mlx, fdf->img->win, y1, x1, color);
// 		else
// 			mlx_pixel_put(fdf->img->mlx, fdf->img->win, x1, y1, color);
// 		if (P < 0)
// 			P += 2 * dy;
// 		else
// 		{
// 			P += 2*dy - 2*dx;
// 			y1 += y_step;
// 		}
// 		++x1;
// 	}
// }

void	draw_map(fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	// while (y < fdf->height)
	// {
	// 	x = 0;
	// 	while (x < fdf->width)
	// 	{
	// 		if (x < fdf->width - 1)
	// 		{
	// 			//bresenham(x, y, x + 1, y, fdf);
	// 			dda(x, y, x + 1, y, fdf);
	// 		}
	// 		if (y < fdf->height - 1)
	// 		{
	// 			//bresenham(x, y, x, y + 1, fdf);
	// 			dda(x, y, x, y + 1, fdf);
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }


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

int	ft_movekey(int key, fdf *m_size)
{

	if (key == 126)
		m_size->pad_h -= 10 ;
	if (key == 125)
		m_size->pad_h += 10;
	if (key == 124)
		m_size->pad_w += 10;
	if (key == 123)
		m_size->pad_w -= 10;
	
	printf("m_size->pad_h%d\n", m_size->pad_h);
	printf("m_size->pad_w%d\n", m_size->pad_w);
	printf("------------------------------\n");
	printf("m_size->win_h%d\n", m_size->win_h);
	printf("m_size->win_w%d\n", m_size->win_w);
	printf("------------------------------\n");
	
	mlx_clear_window(m_size->img->mlx, m_size->img->win);
	mlx_destroy_image(m_size->img->mlx, m_size->img->img);
	m_size->img->img = mlx_new_image(m_size->img->mlx, WIDTH, HEIGHT);
	m_size->img->img_addr = mlx_get_data_addr(m_size->img->img, &m_size->img->bpp, &m_size->img->line_len, &m_size->img->endian);
	draw_map(m_size);
	mlx_put_image_to_window(m_size->img->mlx, m_size->img->win, m_size->img->img, 0, 0);
	return (0);
}
