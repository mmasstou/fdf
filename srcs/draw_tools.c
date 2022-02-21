/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:09:16 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/20 20:09:20 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

char	*ft_title(char *title)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(title, '/');
	split = ft_split(split[1], '.');
	while (split[0][i])
	{
		split[0][i] = ft_toupper(split[0][i]);
		i++;
	}
	return (split[0]);
}

int	re_draw(fdf *data)
{
	mlx_clear_window(data->img->mlx, data->img->win);
	mlx_destroy_image(data->img->mlx, data->img->img);
	data->img->img = mlx_new_image(data->img->mlx, WIDTH, HEIGHT);
	data->img->img_addr = mlx_get_data_addr(data->img->img, \
	&data->img->bpp, &data->img->line_len, &data->img->endian);
	draw_map(data);
	mlx_put_image_to_window(data->img->mlx, \
	data->img->win, data->img->img, 0, 0);
	print_menu(data);
	return (0);
}

void	ft_drawline(fdf *map, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		dst = map->img->img_addr + (y * \
		map->img->line_len + x * (map->img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
