#include "../incs/fdf.h"

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
	if (key == 53)
    	exit(0);

	if (key == ALTITUDE_UP)
		m_size->altitude += 0.31 ;
	if (key == ALTITUDE_DOWN)
	{
		m_size->altitude -= 0.31 ;
		// if (m_size->altitude < ALTITUDE_MIN)
		// 	m_size->altitude = ALTITUDE_MIN;
	}

	if (key == ALPHA_DOWN)
		m_size->beta += 0.12 ,m_size->alpha += 0.12 ;
	if (key == ALPHA_UP)
		m_size->alpha -= 0.12 ,m_size->beta -= 0.12 ;

	if (key == BETA_DOWN)
		m_size->beta += 0.12 ;
	if (key == BETA_UP)
		m_size->beta -= 0.12 ;

	//dddddddddddprintf("++++++++++key+++++++++++ %d\n",key);
	// printf("m_size->beta %f\n",m_size->beta);
	// printf("m_size->alpha %f\n",m_size->alpha);
	// rotation
	if (key == rotate_x_UP)
	{
		m_size->alpha += 0.1;
		m_size->key = rotate_x_UP ;
	}
	if (key == rotate_x_DOWN)
	{
		m_size->alpha -= 0.1;
		m_size->key = rotate_x_DOWN ;
	}

	if (key == rotate_y_UP)
	{
		m_size->alpha += 0.1;
		m_size->key = rotate_y_UP ;
	}
	if (key == rotate_y_DOWN)
	{
		//m_size->beta -= 0.1;
		m_size->alpha -= 0.1;
		m_size->key = rotate_y_DOWN ;
	}

	if (key == rotate_z_UP)
	{
		//m_size->beta += 0.1;
		m_size->alpha += 0.1;
		m_size->key = rotate_z_UP ;
	}
	if (key == rotate_z_DOWN)
	{
		m_size->alpha -= 0.1;
		m_size->key = rotate_z_DOWN ;
	}



	//printf("key = %d\n",key);
	mlx_clear_window(m_size->img->mlx, m_size->img->win);
	mlx_destroy_image(m_size->img->mlx, m_size->img->img);
	m_size->img->img = mlx_new_image(m_size->img->mlx, WIDTH, HEIGHT);
	m_size->img->img_addr = mlx_get_data_addr(m_size->img->img,\
	 &m_size->img->bpp, &m_size->img->line_len, &m_size->img->endian);
	draw_map(m_size);
	mlx_put_image_to_window(m_size->img->mlx, m_size->img->win, m_size->img->img, 0, 0);
	return (0);
}

