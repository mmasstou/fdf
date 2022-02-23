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

void	ft_drawline(t_fdf *map, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < map->win_w) && (y >= 0 && y < map->win_h))
	{
		dst = map->img->img_addr + (y * \
		map->img->line_len + x * (map->img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	pixel_manage(int x, int y, t_fdf *fdf, char c)
{
	fdf->pixel->x1 = x;
	fdf->pixel->y1 = y;
	fdf->pixel->x2 = x;
	fdf->pixel->y2 = y;
	if (c == 'x')
		fdf->pixel->x2 = x + 1;
	if (c == 'y')
		fdf->pixel->y2 = y + 1;
	fdf->pixel->z = fdf->matrix[(int)y][(int)x].z;
	fdf->pixel->z1 = fdf->matrix[(int)fdf->pixel->y2][(int)fdf->pixel->x2].z;
	fdf->pixel->color = fdf->matrix[(int)y][(int)x].color;
}
