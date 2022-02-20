#include "../incs/fdf.h"
static void 	menu_status(fdf *data, int colour)
{
	colour = 0x9efa76;
	mlx_string_put(data->img->mlx, data->img->win, 996, 28, colour, "Status");
	mlx_string_put(data->img->mlx, data->img->win, 10, 20, colour, ft_strjoin(" Map Height : ", ft_itoa(data->height)));
	mlx_string_put(data->img->mlx, data->img->win, 10, 40, colour, ft_strjoin(" Map Width : ", ft_itoa(data->width)));
	if (data->zom > 0)
		colour = 0x9efa76;
	mlx_string_put(data->img->mlx, data->img->win, 10, 60, colour, ft_strjoin(" Zoom : ", ft_itoa(data->zom)));
	colour = 0xFF0001;
	if (data->altitude > 0)
		colour = 0x9efa76;
	mlx_string_put(data->img->mlx, data->img->win, 10, 80, colour, ft_strjoin(" altitude : ", ft_itoa(data->altitude)));
	colour = 0xFF0001;
	if (data->pad_w > 0 && data->pad_w < WIDTH)
		colour = 0x9efa76;
	mlx_string_put(data->img->mlx, data->img->win, 10, 100, colour, ft_strjoin(" x : ", ft_itoa(data->pad_w)));
	colour = 0xFF0001;
	if (data->pad_h > 0 && data->pad_h < HEIGHT)
		colour = 0x9efa76;
	mlx_string_put(data->img->mlx, data->img->win, 10, 120, colour, ft_strjoin(" y : ", ft_itoa(data->pad_h)));
	mlx_string_put(data->img->mlx, data->img->win, 10, 140, 0x9efa76, ft_strjoin(" Colors : ", data->colos_name));
}

void	print_menu(fdf *data)
{
	char	*menu;
	int		colour;

	menu = " Map Title : ";
	menu = ft_strjoin(menu, data->title);
	mlx_string_put(data->img->mlx, data->img->win, 996, 28, 0xFFFB00, menu);

	
	// 
	menu_status(data, colour);

	colour = 0xFF7F00;
	menu = "|-------------------------------------------------|";
	mlx_string_put(data->img->mlx, data->img->win, 14, HEIGHT - 40, colour, menu);
	menu = "| Q/A | W/S | E/D - rotation X/Y/Z                |";
	mlx_string_put(data->img->mlx, data->img->win, 14, HEIGHT - 60, colour, menu);
	menu = "| UP/DOWN/LEFT/RIGHT KEYBOARD KEY                 |";
	mlx_string_put(data->img->mlx, data->img->win, 14,HEIGHT - 80, colour, menu);
	menu = "| SCROLL MOUSE  -> zoom                           |";
	mlx_string_put(data->img->mlx, data->img->win, 14, HEIGHT - 100, colour, menu);
	menu = "| ALTITUDE UP/DOWN   + / -                        |";
	mlx_string_put(data->img->mlx, data->img->win, 14,HEIGHT - 120, colour, menu);
	menu = "| LEFT CLICK AND MOUVE MOUSE TO MOUVE MAP         |";
	mlx_string_put(data->img->mlx, data->img->win, 14,HEIGHT - 140, colour, menu);
	menu = "|  R -> Random Colors || G -> Default color       |";
	mlx_string_put(data->img->mlx, data->img->win, 14,HEIGHT - 160, colour, menu);
	menu = "| 1, 2, 3 - def, iso, paralel projection          |";
	mlx_string_put(data->img->mlx, data->img->win, 14,HEIGHT - 180, colour, menu);
	menu = "|-------------------------------------------------|";
	mlx_string_put(data->img->mlx, data->img->win, 14, HEIGHT - 200, colour, menu);
}