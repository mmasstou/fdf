#include "../incs/fdf.h"

int	ft_movekey(int key, fdf *m_size)
{
	printf("%d\n",key);
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

	if (key == 53)
    {
		mlx_destroy_window(m_size->img->mlx, m_size->img->win);
		exit(0);
	}
	if (key == ALTITUDE_UP)
		m_size->altitude += 0.3 ;
	if (key == ALTITUDE_DOWN)
	{
		m_size->altitude -= 0.3;
		// if (m_size->altitude < ALTITUDE_MIN)
		// 	m_size->altitude = ALTITUDE_MIN;
	}

	if (key == ALPHA_DOWN)
		m_size->alpha += 0.12 ;
	if (key == ALPHA_UP)
		m_size->alpha -= 0.12 ;

	if (key == BETA_DOWN)
		m_size->gama += 0.12 ;
	if (key == BETA_UP)
		m_size->gama -= 0.12 ;


	// colors
	if (key == RANDOM_COLORS)
	{
		m_size->colos_name = ft_strdup("Random");
		m_size->key = RANDOM_COLORS;
	}
	if (key == DEFAULT_COLORS)
	{
		m_size->colos_name = ft_strdup("Default");
		m_size->key = DEFAULT_COLORS;
	}
	
	//dddddddddddprintf("++++++++++key+++++++++++ %d\n",key);
	// printf("m_size->beta %f\n",m_size->beta);
	// printf("m_size->alpha %f\n",m_size->alpha);
	// rotation
	if (key == RO_X_UP)
	{
		m_size->alpha += 0.1;
		m_size->key = RO_X_UP;
	}
	if (key == RO_X_DOWN)
	{
		m_size->alpha -= 0.1;
		m_size->key = RO_X_DOWN ;
	}

	if (key == RO_Y_UP)
	{
		m_size->alpha += 0.1;
		m_size->key = RO_Y_UP ;
	}
	if (key == RO_Y_DOWN)
	{
		//m_size->beta -= 0.1;
		m_size->alpha -= 0.1;
		m_size->key = RO_Y_DOWN ;
	}

	if (key == RO_Z_UP)
	{
		m_size->alpha += 0.1;
		m_size->key = RO_Z_UP ;
	}
	if (key == RO_Z_DOWN)
	{
		m_size->alpha -= 0.1;
		m_size->key = RO_Z_DOWN ;
	}



	//printf("key = %d\n",key);
	mlx_clear_window(m_size->img->mlx, m_size->img->win);
	mlx_destroy_image(m_size->img->mlx, m_size->img->img);
	m_size->img->img = mlx_new_image(m_size->img->mlx, WIDTH, HEIGHT);
	m_size->img->img_addr = mlx_get_data_addr(m_size->img->img,\
	 &m_size->img->bpp, &m_size->img->line_len, &m_size->img->endian);
	draw_map(m_size);
	mlx_put_image_to_window(m_size->img->mlx, m_size->img->win, m_size->img->img, 0, 0);
	print_menu(m_size);
	return (0);
}

