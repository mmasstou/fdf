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
		m_size->altitude += 0.21 ;
	if (key == ALTITUDE_DOWN)
	{
		m_size->altitude -= 0.21 ;
		if (m_size->altitude < ALTITUDE_MIN)
			m_size->altitude = ALTITUDE_MIN;
	}

	if (key == ALPHA_DOWN)
		m_size->alpha += 0.1 ;
	if (key == ALPHA_UP)
		m_size->alpha -= 0.1 ;


	printf("key = %d\n",key);
	mlx_clear_window(m_size->img->mlx, m_size->img->win);
	mlx_destroy_image(m_size->img->mlx, m_size->img->img);
	m_size->img->img = mlx_new_image(m_size->img->mlx, WIDTH, HEIGHT);
	m_size->img->img_addr = mlx_get_data_addr(m_size->img->img,\
	 &m_size->img->bpp, &m_size->img->line_len, &m_size->img->endian);
	draw_map(m_size);
	mlx_put_image_to_window(m_size->img->mlx, m_size->img->win, m_size->img->img, 0, 0);
	return (0);
}

