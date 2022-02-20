#include "../incs/fdf.h"

void img_init(t_data_img *map_data)
{
	map_data->endian = 0;
	map_data->line_len = WIDTH * 4;
	map_data->bpp = 32;
	map_data->mlx = mlx_init();
}

fdf	*data_init()
{
	fdf	*map_data;

	map_data = (fdf *)malloc(sizeof(fdf));
	if (!map_data)
		return (NULL);
	map_data->img = (t_data_img *)malloc(sizeof(t_data_img));
	if (!map_data->img)
		return (NULL);
	map_data->pos_m = (mouse *)malloc(sizeof(mouse));
	if (!map_data->pos_m)
		return (NULL);
	map_data->alpha = 0.523599 ;
	map_data->beta = 0.523599 ;
	map_data->key = -1;
	map_data->colos_name = ft_strdup("Default");
	map_data->color_auto = true;
	return (map_data);
}