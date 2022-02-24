/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:05:50 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 18:05:52 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	ft_close(int key, t_fdf *m_size)
{
	if (key == 53)
	{
		mlx_destroy_window(m_size->img->mlx, m_size->img->win);
		exit(0);
	}
	return (0);
}

void	ft_mange_win(char **argv, int argc, t_fdf *d)
{
	if (argc == 4)
		ft_zoom(d, ft_atoi(argv[2]), ft_atoi(argv[3]));
	else
		ft_zoom(d, 0, 0);
	img_init(d->img);
	resolution(d);
	padding_bonus(d);
	d->img->win = mlx_new_window(d->img->mlx, d->win_w, d->win_h, "FDF");
	d->img->img = mlx_new_image(d->img->mlx, d->win_w, d->win_h);
	d->img->img_addr = mlx_get_data_addr(d->img->img, &d->img->bpp, \
	&d->img->line_len, &d->img->endian);
	draw_map(d);
	mlx_put_image_to_window(d->img->mlx, d->img->win, d->img->img, 0, 0);
	mlx_hook(d->img->win, 2, 1L << 0, ft_close, d);
}

int	main(int argc, char *argv[])
{
	t_fdf	*map_data;

	map_data = data_init();
	if (map_data == NULL)
		return (EXIT_FAILURE);
	if ((argc >= 2 && argc <= 4) && check_fd(argv[1], map_data))
	{
		if (argc == 2 || argc == 4)
		{
			ft_readfile(map_data, argv[1]);
			ft_mange_win(argv, argc, map_data);
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
	return (EXIT_SUCCESS);
}
