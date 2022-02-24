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

static void	int_defualt(t_fdf *d)
{
	d->def->zoom = d->zom;
	d->def->altitude = d->altitude;
	d->def->pad_h = d->pad_h;
	d->def->pad_w = d->pad_w;
}

void	ft_mange_win_bonus(char **argv, int argc, t_fdf *d)
{
	if (argc == 4)
		ft_zoom(d, ft_atoi(argv[2]), ft_atoi(argv[3]));
	else
		ft_zoom(d, 0, 0);
	img_init(d->img);
	d->title = ft_title(argv[1]);
	resolution(d);
	padding_bonus(d);
	d->img->win = mlx_new_window(d->img->mlx, d->win_w, d->win_h, "FDF");
	d->img->img = mlx_new_image(d->img->mlx, d->win_w, d->win_h);
	d->img->img_addr = mlx_get_data_addr(d->img->img, &d->img->bpp, \
	&d->img->line_len, &d->img->endian);
	int_defualt(d);
	draw_map_bonus(d);
	mlx_put_image_to_window(d->img->mlx, d->img->win, d->img->img, 0, 0);
	print_menu(d);
	mlx_hook(d->img->win, 2, 1L << 0, ft_movekey, d);
	mlx_hook(d->img->win, 4, 1L << 0, ft_mousekey, d);
	mlx_hook(d->img->win, 6, 1L << 0, ft_mouse_move, d);
	mlx_hook(d->img->win, 5, 1L << 0, ft_mouse_click_up, d);
	mlx_hook(d->img->win, 17, 1L << 0, x_button, d);
}

int	main(int argc, char *argv[])
{
	t_fdf	*map_data;

	map_data = data_init();
	if ((argc >= 2 && argc <= 4) && check_fd(argv[1], map_data))
	{
		if (argc == 2 || argc == 4)
		{
			ft_readfile(map_data, argv[1]);
			ft_mange_win_bonus(argv, argc, map_data);
			mlx_loop(map_data->img->mlx);
		}
		else
			return (ft_putstr_fd("Usage : ./fdf <filename> \
			[ case_size z_size ]\n", 2), 1);
	}
	else
		return (ft_putstr_fd("Usage : ./fdf <filename> \
		[ case_size z_size ]\n", 2), 1);
	fdf_free(map_data);
}
