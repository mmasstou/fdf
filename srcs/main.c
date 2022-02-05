#include "../incs/fdf.h"


int main(int argc, char *argv[])
{
	fdf	*map_data;
	// int y;
	// int x;

	map_data = (fdf *)malloc(sizeof(fdf));
	if (!map_data)
		return (0);
	if (argc == 2)
		ft_readfile(map_data, argv[1]);

	map_data->img = (t_data_img *)malloc(sizeof(t_data_img));

	map_data->zom = ZOOM(map_data->height); 
	map_data->pad_w = (WIDTH / 2) - (map_data->width / 2) - map_data->zom;
	map_data->pad_h = (HEIGHT / 2) - (map_data->height / 2) - map_data->zom;
	map_data->img->mlx = mlx_init();
	map_data->img->win = mlx_new_window(map_data->img->mlx, WIDTH, HEIGHT, "FdF");
	//map_data->img->img.img = mlx_new_image(map_data->img->mlx, 800, 600);
	//map_data->img->img.addr = mlx_get_data_addr(map_data->img->img.img, &map_data->img->img.bpp, &map_data->img->img.line_len,
	//		&map_data->img->img.endian);
	// custom_mlx_pixel_put(&map_data->img->img, 10, 10, 0x00FF00FF);
	//mlx_put_image_to_window(map_data->img->mlx, map_data->img->win, map_data->img->img.img, 0, 0);
	draw_map(map_data);
	//bresenham(50, 50, 100, 100, fdf);
	//mlx_key_hook(map_data->img->win, shift_keys, fdf);
	//mlx_hook(map_data->img->win, 2, 1L<<0, close_win, fdf);
	mlx_loop(map_data->img->mlx);
	// y = 0;
	// while (y < map_data->height )
	// {
	// 	x = 0;
	// 	while (x < map_data->width)
	// 	{
	// 		if (map_data->matrix[y][x].color == -1)
	// 			printf("%d",map_data->matrix[y][x].z);
	// 		else
	// 			printf(" %2d,%8d",map_data->matrix[y][x].z,map_data->matrix[y][x].color);
	// 		x++;
	// 	}
	// 	printf("\n");
	// 	y++;
	// }
	return (0);
}