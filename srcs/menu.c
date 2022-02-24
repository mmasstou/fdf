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
	char	*val;

	colour = 0xFF0001;
	if (d->altitude > 0)
		colour = 0x9efa76;
	val = ft_itoa(d->altitude);
	print_line(d, 100, colour, ft_strjoin(" altitude : ", val));
	free(val);
	colour = 0xFF0001;
	if (d->pad_w > 0 && d->pad_w < d->win_w)
		colour = 0x9efa76;
	val = ft_itoa(d->pad_w);
	print_line(d, 120, colour, ft_strjoin(" x : ", val));
	free(val);
	colour = 0xFF0001;
	if (d->pad_h > 0 && d->pad_h < d->win_h)
		colour = 0x9efa76;
	val = ft_itoa(d->pad_h);
	print_line(d, 140, colour, ft_strjoin(" y : ", val));
	free(val);
}

static void	menu_status3(t_fdf *d, int color)
{
	char	*val;

	print_line(d, 160, color, ft_strjoin(" Colors : ", d->colos_name));
	val = ft_itoa(d->alpha);
	print_line(d, 180, color, ft_strjoin(" Alpha (x rotation) : ", val));
	free(val);
	val = ft_itoa(d->beta);
	print_line(d, 200, color, ft_strjoin(" Beta (y rotation) : ", val));
	free(val);
	val = ft_itoa(d->gama);
	print_line(d, 220, color, ft_strjoin(" Gamma (z rotation) : ", val));
	free(val);
	print_line(d, 240, color, ft_strjoin(" Projection : ", d->projection_name));
}

static void	menu_status1(t_fdf *d, int colour)
{
	char	*menu;
	char	*val;

	colour = 0x9efa76;
	mlx_string_put(d->img->mlx, d->img->win, 10, 20, colour, "Status");
	val = ft_itoa(d->height);
	menu = ft_strjoin(" Map Height : ", val);
	mlx_string_put(d->img->mlx, d->img->win, 10, 40, colour, menu);
	free(val);
	free(menu);
	val = ft_itoa(d->width);
	menu = ft_strjoin(" Map Width : ", val);
	mlx_string_put(d->img->mlx, d->img->win, 10, 60, colour, menu);
	free(val);
	free(menu);
	if (d->zom < 0)
		colour = 0xFF0001;
	val = ft_itoa(d->zom);
	menu = ft_strjoin(" Zoom : ", val);
	mlx_string_put(d->img->mlx, d->img->win, 10, 80, colour, menu);
	free(val);
	free(menu);
}

static void	map_key1(t_fdf *d, int c)
{
	char	*menu;

	c = 0xFF7F00;
	menu = "|-------------------------------------------------|";
	mlx_string_put(d->img->mlx, d->img->win, 14, d->win_h - 60, c, menu);
	menu = "| Q/A | W/S | E/D - rotation X/Y/Z                |";
	mlx_string_put(d->img->mlx, d->img->win, 14, d->win_h - 80, c, menu);
	menu = "| UP/DOWN/LEFT/RIGHT KEYBOARD KEY                 |";
	mlx_string_put(d->img->mlx, d->img->win, 14, d->win_h - 100, c, menu);
	menu = "| SCROLL MOUSE  -> zoom                           |";
	mlx_string_put(d->img->mlx, d->img->win, 14, d->win_h - 120, c, menu);
	menu = "| ALTITUDE UP/DOWN   + / -                        |";
	mlx_string_put(d->img->mlx, d->img->win, 14, d->win_h - 140, c, menu);
	menu = "| LEFT CLICK AND MOUVE MOUSE TO MOUVE MAP         |";
	mlx_string_put(d->img->mlx, d->img->win, 14, d->win_h - 160, c, menu);
	menu = "|  R -> Random Colors || G -> Default color       |";
	mlx_string_put(d->img->mlx, d->img->win, 14, d->win_h - 180, c, menu);
	menu = "| 0, I, P - def, iso, paralel projection          |";
	mlx_string_put(d->img->mlx, d->img->win, 14, d->win_h - 200, c, menu);
	menu = "| Map Key ----------------------------------------|";
	mlx_string_put(d->img->mlx, d->img->win, 14, d->win_h - 220, c, menu);
}

void	print_menu(t_fdf *data)
{
	int		colour;
	char	*menu;

	colour = 0xFFFB00;
	menu = ft_strjoin(" Map Title : ", data->title);
	mlx_string_put(data->img->mlx, data->img->win, data->win_w - \
	1.5 * (data->win_w / 3), 40, colour, menu);
	free(menu);
	menu_status1(data, colour);
	menu_status2(data, colour);
	menu_status3(data, 0x9efa76);
	map_key1(data, colour);
}
