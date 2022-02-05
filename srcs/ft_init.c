#include "../incs/fdf.h"


void	store_data_init(store_data *m_data)
{
	m_data->x = 0;
	m_data->y = 0;

}

void img_init(t_data_img *map_data)
{
	map_data->endian = 0;
	map_data->line_len = 1920 * 4;
	map_data->bpp = 32;
	map_data->mlx = mlx_init();
}