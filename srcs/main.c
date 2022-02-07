#include "../incs/fdf.h"


void	ft_zoom(fdf *map)
{
	float  c;
	int		x;
	// int	height;
	// int	width;

	// height = map->win_h;
	// height -= (map->win_h / 0.75);
	// height /= map->zom;

	// width = map->win_w;
	// width -= (map->win_w / 0.25);
	// width /= map->zom;

	x = MAX(map->height, map->width);
	printf("x | =%d\n",x);
	c = (x - 20) / 26.6666666667 ; 
	map->zom = 20 - c;
	printf("map->zom| =%d\n",map->zom);
}
void	ft_mange_win(char *argv1, fdf *map_data)
{
	char **split;


	split = ft_split(argv1, '/');
	printf("%s\n",split[1]);
	//split = ft_split(split[-2], '.');
	
	ft_zoom(map_data) ;
	img_init(map_data->img);
	// map_data->pad_w = (WIDTH / 2) - ((map_data->width / 4) - 90);
	// map_data->pad_h = (HEIGHT / 2) - ((map_data->height / 6) + 420);
	// map_data->height *= map_data->zom;
	// map_data->width *= map_data->zom;

	

	map_data->win_h = map_data->width;
	map_data->win_h += ( map_data->width * .25);	
	

	map_data->win_w = map_data->height;
	map_data->win_w += ( map_data->height * .75);	
	
	map_data->win_w *= map_data->zom;
	map_data->win_h *= map_data->zom;

	if (map_data->win_w >= 2592)
		map_data->win_w = 2592;
	if (map_data->win_h >= 1640)
		map_data->win_h = 1640;

	map_data->pad_w = ((map_data->win_w  - map_data->width)/ 2);
	map_data->pad_h = ((map_data->win_w - map_data->height)/ 2) + 42;



	map_data->pad_w = map_data->win_w / 2;
	map_data->pad_h = map_data->win_h / 6;


	// printf("map_data->zom  = %d\n",map_data->zom);
	// printf("map_data->pad_w  = %d\n",map_data->pad_w);
	// printf("map_data->pad_h  = %d\n",map_data->pad_h);

	map_data->img->mlx = mlx_init();
	map_data->img->win = mlx_new_window(map_data->img->mlx, map_data->win_w, map_data->win_h, split[1]);

	map_data->img->img = mlx_new_image(map_data->img->mlx, map_data->win_w, map_data->win_h);
	map_data->img->img_addr = mlx_get_data_addr(map_data->img->img, &map_data->img->bpp, &map_data->img->line_len, &map_data->img->endian);
	draw_map(map_data);
	mlx_put_image_to_window(map_data->img->mlx, map_data->img->win, map_data->img->img, 0, 0);
	// map_data->pad_h *= map_data->zom;
	// map_data->pad_w *= map_data->zom;
	mlx_hook(map_data->img->win, 2, 1L<<0, ft_movekey, map_data);

	// map_data->pad_w *= map_data->zom;
	// map_data->pad_h *= map_data->zom;
}

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
	printf("map_data->height |%d\n",map_data->height);
	printf("map_data->width |%d\n",map_data->width);
	map_data->img = (t_data_img *)malloc(sizeof(t_data_img));

	ft_mange_win(argv[1], map_data);
	// map_data->zom = ZOOM(map_data->height); 
	// map_data->pad_w = (WIDTH / 2) - ((map_data->width / 4) - 90);
	// map_data->pad_h = (HEIGHT / 2) - ((map_data->height / 4) + 120);
	// map_data->img->mlx = mlx_init();
	// map_data->img->win = mlx_new_window(map_data->img->mlx, WIDTH, HEIGHT, "FdF5vfgfg");
	//map_data->img->img.img = mlx_new_image(map_data->img->mlx, 800, 600);
	//map_data->img->img.addr = mlx_get_data_addr(map_data->img->img.img, &map_data->img->img.bpp, &map_data->img->img.line_len,
	//		&map_data->img->img.endian);
	// custom_mlx_pixel_put(&map_data->img->img, 10, 10, 0x00FF00FF);
	//mlx_put_image_to_window(map_data->img->mlx, map_data->img->win, map_data->img->img.img, 0, 0);
	//draw_map(map_data);
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