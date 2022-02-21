/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:25:45 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/20 18:25:53 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	menu_status2(t_fdf *d, int colour)
{
	colour = 0xFF0001;
	if (d->altitude > 0)
		colour = 0x9efa76;
	mlx_string_put(d->img->mlx, d->img->win, 10, 100, colour,
		ft_strjoin(" altitude : ", ft_itoa(d->altitude)));
	colour = 0xFF0001;
	if (d->pad_w > 0 && d->pad_w < WIDTH)
		colour = 0x9efa76;
	mlx_string_put(d->img->mlx, d->img->win, 10, 120, colour,
		ft_strjoin(" x : ", ft_itoa(d->pad_w)));
	colour = 0xFF0001;
	if (d->pad_h > 0 && d->pad_h < HEIGHT)
		colour = 0x9efa76;
	mlx_string_put(d->img->mlx, d->img->win, 10, 140, colour,
		ft_strjoin(" y : ", ft_itoa(d->pad_h)));
	mlx_string_put(d->img->mlx, d->img->win, 10, 160, 0x9efa76,
		ft_strjoin(" Colors : ", d->colos_name));
}

static void	menu_status1(t_fdf *d, int colour)
{
	colour = 0x9efa76;
	mlx_string_put(d->img->mlx, d->img->win, 10, 20, colour, "Status");
	mlx_string_put(d->img->mlx, d->img->win, 10, 40, colour,
		ft_strjoin(" Map Height : ", ft_itoa(d->height)));
	mlx_string_put(d->img->mlx, d->img->win, 10, 60, colour,
		ft_strjoin(" Map Width : ", ft_itoa(d->width)));
	if (d->zom < 0)
		colour = 0xFF0001;
	mlx_string_put(d->img->mlx, d->img->win, 10, 80, colour,
		ft_strjoin(" Zoom : ", ft_itoa(d->zom)));
}

static void	map_key1(t_fdf *d, int c)
{
	char	*menu;

	c = 0xFF7F00;
	menu = "|-------------------------------------------------|";
	mlx_string_put(d->img->mlx, d->img->win, 14, HEIGHT - 40, c, menu);
	menu = "| Q/A | W/S | E/D - rotation X/Y/Z                |";
	mlx_string_put(d->img->mlx, d->img->win, 14, HEIGHT - 60, c, menu);
	menu = "| UP/DOWN/LEFT/RIGHT KEYBOARD KEY                 |";
	mlx_string_put(d->img->mlx, d->img->win, 14, HEIGHT - 80, c, menu);
	menu = "| SCROLL MOUSE  -> zoom                           |";
	mlx_string_put(d->img->mlx, d->img->win, 14, HEIGHT - 100, c, menu);
	menu = "| ALTITUDE UP/DOWN   + / -                        |";
	mlx_string_put(d->img->mlx, d->img->win, 14, HEIGHT - 120, c, menu);
	menu = "| LEFT CLICK AND MOUVE MOUSE TO MOUVE MAP         |";
	mlx_string_put(d->img->mlx, d->img->win, 14, HEIGHT - 140, c, menu);
	menu = "|  R -> Random Colors || G -> Default color       |";
	mlx_string_put(d->img->mlx, d->img->win, 14, HEIGHT - 160, c, menu);
	menu = "| 1, 2, 3 - def, iso, paralel projection          |";
	mlx_string_put(d->img->mlx, d->img->win, 14, HEIGHT - 180, c, menu);
	menu = "| Map Key ----------------------------------------|";
	mlx_string_put(d->img->mlx, d->img->win, 14, HEIGHT - 200, c, menu);
}

void	print_menu(t_fdf *data)
{
	int		colour;

	colour = 0xFFFB00;
	mlx_string_put(data->img->mlx, data->img->win, 996, 28, colour,
		ft_strjoin(" Map Title : ", data->title));
	menu_status1(data, colour);
	menu_status2(data, colour);
	map_key1(data, colour);
}
