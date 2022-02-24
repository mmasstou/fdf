/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:07:46 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 18:07:50 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	resolution(t_fdf *fdf)
{
	float	x;
	float	y;

	x = cos(1.047) * (fdf->height * fdf->zom);
	y = cos(0.523599) * (fdf->width * fdf->zom);
	fdf->win_w = (x + y) + x;
	fdf->win_w += get_percent(fmax(fdf->height, fdf->width), 55) + 100;
	x = sin(0.523599) * fdf->width * fdf->zom;
	y = cos(0.523599) * fdf->height * fdf->zom;
	fdf->win_h = (x + y);
	fdf->win_h += get_percent(fmax(fdf->height, fdf->width), 5);
}

float	get_percent(int val, int perc)
{
	return ((val * perc) / 100);
}
