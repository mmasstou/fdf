/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:32:24 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/20 19:32:28 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	ft_win_resolution(fdf *map_data)
{
	map_data->win_h = WIDTH;
	map_data->win_h += (map_data->win_h * .25);
	map_data->win_h *= map_data->zom;
	map_data->win_w = HEIGHT;
	map_data->win_w += (map_data->win_w * .75);
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

void	ft_mange_win(char **argv, int argc, fdf *d)
{
	if (argc == 4)
		ft_zoom(d, ft_atoi(argv[2]), ft_atoi(argv[3]));
	else
		ft_zoom(d, 0, 0);
	img_init(d->img);
	d->title = ft_title(argv[1]);
	ft_win_resolution(d);
	ft_padding(d);
	d->img->win = mlx_new_window(d->img->mlx, WIDTH, HEIGHT, "FDF");
	d->img->img = mlx_new_image(d->img->mlx, WIDTH, HEIGHT);
	d->img->img_addr = mlx_get_data_addr(d->img->img, &d->img->bpp, \
	&d->img->line_len, &d->img->endian);
	draw_map(d);
	mlx_put_image_to_window(d->img->mlx, d->img->win, d->img->img, 0, 0);
	print_menu(d);
	mlx_hook(d->img->win, 2, 1L << 0, ft_movekey, d);
	mlx_hook(d->img->win, 4, 1L << 0, ft_mousekey, d);
	mlx_hook(d->img->win, 6, 1L << 0, ft_mouse_move, d);
	mlx_hook(d->img->win, 5, 1L << 0, ft_mouse_click_up, d);
}

int	main(int argc, char *argv[])
{
	fdf	*map_data;

	map_data = data_init();
	if ((argc >= 2 && argc <= 4) && check_fd(argv[1]))
	{
		if (argc == 2 || argc == 4)
		{
			ft_readfile(map_data, argv[1]);
			ft_mange_win(argv, argc, map_data);
			mlx_loop(map_data->img->mlx);
			free(map_data);
			free(map_data->img);
			free(map_data->pos_m);
		}
		else
			return (ft_putstr_fd("Usage : ./fdf <filename> \
			[ case_size z_size ]\n", 2), 1);
	}
	else
		return (ft_putstr_fd("Usage : ./fdf <filename> \
		[ case_size z_size ]\n", 2), 1);
}
