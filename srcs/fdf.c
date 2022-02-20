#include "../incs/fdf.h"

// void		ft_zoom(fdf *data)
// {
// 	data->altitude = 1.2;
// 	if (data->width >= 100)
// 		data->zom = ((WIDTH / data->width) / 2) + 4;
// 	else
// 		data->zom = (WIDTH / (data->height * data->height ) + data->height) + 6;
// }

void	ft_padding(fdf *map_data)
{
	float	x;
	float	y;

	x = cos(M_PI_2 - ALPHA) * (map_data->height * map_data->zom);
	y = cos(ALPHA) * (map_data->width * map_data->zom);
	map_data->pad_w =  WIDTH - (x + y);
	map_data->pad_w /= 2;
	map_data->pad_w += x;
	x = sin(ALPHA) * map_data->width * map_data->zom;
	y = sin(M_PI_2 - ALPHA) * map_data->height * map_data->zom;
	map_data->pad_h = HEIGHT - (x + y);
	map_data->pad_h /= 2;
	map_data->pad_h += (x / 2);
}

void	ft_win_resolution(fdf *map_data)
{
	map_data->win_h = WIDTH;
	map_data->win_h += ( map_data->win_h * .25);	
	map_data->win_h *= map_data->zom;
	map_data->win_w = HEIGHT;
	map_data->win_w += ( map_data->win_w * .75);	
	map_data->win_w *= map_data->zom;
	if (map_data->win_w >= 2592)
	{
		map_data->win_w = 2592;
		map_data->zom -= 1.6;
	}
	if (map_data->win_h >= 1440)
	{
		map_data->win_h = 1440;
		map_data->zom -= 1.4;
	}
}

// void	ft_mange_win(char *argv1, fdf *map_data)
// {
// 	ft_zoom(map_data) ;
// 	img_init(map_data->img);
// 	ft_win_resolution(map_data);
// 	ft_padding(map_data);
// 	map_data->img->mlx = mlx_init();
// 	map_data->img->win = mlx_new_window(map_data->img->mlx,WIDTH, HEIGHT, ft_title(argv1));
// 	map_data->img->img = mlx_new_image(map_data->img->mlx,WIDTH, HEIGHT);
// 	map_data->img->img_addr = mlx_get_data_addr(map_data->img->img, &map_data->img->bpp, &map_data->img->line_len, &map_data->img->endian);
// 	draw_map(map_data);
// 	mlx_put_image_to_window(map_data->img->mlx, map_data->img->win, map_data->img->img, 0, 0);
// 	mlx_hook(map_data->img->win, 2, 1L<<0, ft_close, map_data);
// }

int main(int argc, char *argv[])
{
	fdf	*map_data;

	map_data = (fdf *)malloc(sizeof(fdf));
	if (!map_data)
		return (0);
	if (argc >= 2 && argc <= 4)
		{
			if (argc == 3)
				return(printf("Usage : ./fdf <filename> [ case_size z_size ]\n"),0);
			else if (argc == 2)
			{
				ft_readfile(map_data, argv[1]);
				map_data->img = (t_data_img *)malloc(sizeof(t_data_img));
				if (!map_data->img)
					return (0);
				map_data->alpha = 0.8;
				ft_mange_win(argv, argc, map_data);
				mlx_loop(map_data->img->mlx);
			}
			else 
				return(printf("NOT YET .... !\n"),0);
		}
		else 
			return(printf("Usage : ./fdf <filename> Or ./fdf <filename> [ case_size z_size ] \n"),0);
}