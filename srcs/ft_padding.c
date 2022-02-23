/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:51:56 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/20 18:51:59 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	padding_bonus(t_fdf *fdf)
{
	float	x;
	float	y;

	x = cos(fdf->alpha) * (fdf->height * fdf->zom);
	y = cos(fdf->alpha) * (fdf->width * fdf->zom);
	fdf->pad_w = fdf->win_w - (x + y);
	fdf->pad_w /= 2;
	fdf->pad_w += x;
	x = sin(fdf->alpha) * fdf->width * fdf->zom;
	y = sin(fdf->alpha) * fdf->height * fdf->zom;
	fdf->pad_h = fdf->win_h - (x + y);
	fdf->pad_h /= 2;
	fdf->pad_h += fmax(x, y);
}

void	padding(t_fdf *fdf)
{
	fdf->pad_w = get_percent(fdf->width, 350);
	fdf->pad_h = get_percent(fdf->height, 45);
}
