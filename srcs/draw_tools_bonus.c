/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:09:16 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/25 11:55:38 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

char	*ft_title(char *title)
{
	int		i;
	char	**split;
	char	**tab;

	i = 0;
	split = ft_split(title, '/');
	while (split[i])
		i++;
	tab = ft_split(split[i - 1], '.');
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	i = 0;
	while (tab[0][i])
	{
		tab[0][i] = ft_toupper(tab[0][i]);
		i++;
	}
	free(tab[1]);
	free(tab);
	return (tab[0]);
}

int	re_draw(t_fdf *data)
{
	mlx_clear_window(data->img->mlx, data->img->win);
	mlx_destroy_image(data->img->mlx, data->img->img);
	data->img->img = mlx_new_image(data->img->mlx, data->win_w, data->win_h);
	data->img->img_addr = mlx_get_data_addr(data->img->img, \
	&data->img->bpp, &data->img->line_len, &data->img->endian);
	draw_map_bonus(data);
	mlx_put_image_to_window(data->img->mlx, \
	data->img->win, data->img->img, 0, 0);
	print_menu(data);
	return (0);
}
