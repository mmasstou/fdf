#include "../incs/fdf.h"


void	print_menu(fdf *data)
{
	char	*menu;
	int		colour;

	
	
	menu = " Map Title : ";
	menu = ft_strjoin(menu, data->title);
	mlx_string_put(data->img->mlx, data->img->win, 996, 28, 0xFFFB00, menu);
	
	// menu = "BUTTON 1 - rotation mouse";
	// mlx_string_put(data->img->mlx, data->img->win, 10, 30, colour, menu);

	
	// menu = "1, 2, 3 - def, iso, paralel projection";
	// mlx_string_put(data->img->mlx, data->img->win, 10, 75, colour, menu);
// 	menu = "4 - simple colour";
// 	mlx_string_put(data->img->mlx, data->img->win, 10, 90, colour, menu);

	colour = 0x9efa76;
	menu = " Map Height : ";
	menu = ft_strjoin(menu, ft_itoa(data->height));
	mlx_string_put(data->img->mlx, data->img->win, 10, 20, colour, menu);

	menu = " Map Width : ";
	menu = ft_strjoin(menu, ft_itoa(data->width));
	mlx_string_put(data->img->mlx, data->img->win, 10, 40, colour, menu);
	menu = " Zoom : ";
	menu = ft_strjoin(menu, ft_itoa(data->zom));
	if (data->zom > 0)
		colour = 0x9efa76;
	mlx_string_put(data->img->mlx, data->img->win, 10, 60, colour, menu);
	colour = 0xFF0001;
	menu = " altitude : ";
	menu = ft_strjoin(menu, ft_itoa(data->altitude));
	if (data->altitude > 0)
		colour = 0x9efa76;
	mlx_string_put(data->img->mlx, data->img->win, 10, 80, colour, menu);
	colour = 0xFF0001;

	menu = " x : ";
	menu = ft_strjoin(menu, ft_itoa(data->pad_w));
	if (data->pad_w > 0 && data->pad_w < WIDTH)
		colour = 0x9efa76;
	mlx_string_put(data->img->mlx, data->img->win, 10, 100, colour, menu);
	colour = 0xFF0001;
	menu = " y : ";
	menu = ft_strjoin(menu, ft_itoa(data->pad_h));
	if (data->pad_h > 0 && data->pad_h < HEIGHT)
		colour = 0x9efa76;
	mlx_string_put(data->img->mlx, data->img->win, 10, 120, colour, menu);
	menu = " Colors : ";
	menu = ft_strjoin(menu, data->colos);
	mlx_string_put(data->img->mlx, data->img->win, 10, 140, 0x9efa76, menu);
	// 
	colour = 0xFF7F00;
	menu = " UP/DOWN/LEFT/RIGHT KEYBOARD KEY";
	mlx_string_put(data->img->mlx, data->img->win, 10,HEIGHT - 60, colour, menu);
	menu = " Q/A | W/S | E/D - rotation X/Y/Z ";
	mlx_string_put(data->img->mlx, data->img->win, 10, HEIGHT - 40, colour, menu);
	menu = " SCROLL MOUSE  -> zoom ";
	mlx_string_put(data->img->mlx, data->img->win, 10, HEIGHT - 80, colour, menu);
	menu = " ALTITUDE UP/DOWN   + / -";
	mlx_string_put(data->img->mlx, data->img->win, 10,HEIGHT - 100, colour, menu);
	menu = " LEFT CLICK AND MOUVE MOUSE TO MOUVE MAP";
	mlx_string_put(data->img->mlx, data->img->win, 10,HEIGHT - 120, colour, menu);
}


void		ft_zoom(fdf *data, int _altitude, int _zoom)
{
	if (_altitude == 0 ||  _zoom == 0)
	{
		data->altitude = 1;
		if (data->width >= 100)
			data->zom = ((WIDTH / data->width) / 2) + 3;
		else
			data->zom = (HEIGHT / (data->height * data->height ) + data->height) + 26;
		printf("(_altitude == %f ||  _zoom == %f)\n",data->altitude,data->zom);
	}
	else
	{
		printf("(_altitude == %d ||  _zoom == %d)\n",_altitude,_zoom);
		data->altitude = _altitude;
		data->zom = _zoom;
}
	}


void	ft_padding(fdf *map_data)
{
	float	x;
	float	y;

	x = cos(map_data->alpha) * (map_data->height * map_data->zom);
	y = cos(map_data->alpha) * (map_data->width * map_data->zom);
	map_data->pad_w =  WIDTH - (x + y);
	map_data->pad_w /= 2;
	map_data->pad_w += x;
	x = sin(map_data->alpha) * map_data->width * map_data->zom;
	y = sin(map_data->alpha) * map_data->height * map_data->zom;
	map_data->pad_h = HEIGHT - (x + y);
	map_data->pad_h /= 2;
	map_data->pad_h += MAX(x,y) / 2;
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
/*
** 02: keyPress
** 04: ButtonPress
** 05: ButtonRelease
** 06: MotionNotify
** 17: DestroyNotify
*/
void	ft_mange_win(char **argv, int argc, fdf *map_data)
{

	if (argc == 4)
		ft_zoom(map_data, ft_atoi(argv[2]),ft_atoi(argv[3])) ;
	else 
		ft_zoom(map_data, 0, 0);
	img_init(map_data->img);
	map_data->title = ft_title(argv[1]);
	ft_win_resolution(map_data);
	ft_padding(map_data);
	map_data->img->win = mlx_new_window(map_data->img->mlx,WIDTH, HEIGHT, "FDF");
	map_data->img->img = mlx_new_image(map_data->img->mlx,WIDTH, HEIGHT);
	map_data->img->img_addr = mlx_get_data_addr(map_data->img->img, &map_data->img->bpp, &map_data->img->line_len, &map_data->img->endian);
	draw_map(map_data);
	mlx_put_image_to_window(map_data->img->mlx, map_data->img->win, map_data->img->img, 0, 0);
	print_menu(map_data);
	mlx_hook(map_data->img->win, 2, 1L<<0, ft_movekey, map_data);
	mlx_hook(map_data->img->win, 4, 1L<<0, ft_mousekey, map_data);
	mlx_hook(map_data->img->win, 6, 1L<<0, ft_mouse_move, map_data);
	mlx_hook(map_data->img->win, 5, 1L<<0, ft_mouse_click_up, map_data);
}



int main(int argc, char *argv[])
{
	fdf	*map_data;

	map_data = (fdf *)malloc(sizeof(fdf));
	if (!map_data)
		return (0);
	if ((argc >= 2 && argc <= 4) && check_fd(argv[1]))
	{
		if (argc == 2 || argc == 4)
		{
			ft_readfile(map_data, argv[1]);
			map_data->img = (t_data_img *)malloc(sizeof(t_data_img));
			map_data->pos_m = (mouse *)malloc(sizeof(mouse));
			if (!map_data->img)
				return (0);
			map_data->alpha = 0.523599 ;
			map_data->beta = 0.523599 ;
			map_data->gama = 0.523599 ;
			map_data->key = -1;
			map_data->colos = ft_strdup("Non");
			ft_mange_win(argv, argc, map_data);
			mlx_loop(map_data->img->mlx);
		}
		else 
			return(ft_putstr_fd("Usage : ./fdf <filename> [ case_size z_size ]\n",2),1);
	}
	else 
		return(ft_putstr_fd("Usage : ./fdf <filename> [ case_size z_size ]\n",2),1);
}
