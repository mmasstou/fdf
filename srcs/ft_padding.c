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

	x = cos(1.047) * (fdf->height * fdf->zom);
	y = cos(0.523599) * (fdf->width * fdf->zom);
	fdf->pad_w = fdf->win_w - (x + y);
	fdf->pad_w /= 2;
	fdf->pad_w += x * 1.5;
	x = sin(0.523599) * fdf->width * fdf->zom;
	y = cos(0.523599) * fdf->height * fdf->zom;
	fdf->pad_h = fdf->win_h - (x + y);
	fdf->pad_h /= 2;
	fdf->pad_h += fabs(x) / 3;
	fdf->pad_h += fdf->height * fdf->zom / 2 ;
}

void	padding(t_fdf *fdf)
{
	fdf->pad_w = get_percent(fdf->width, 350);
	fdf->pad_h = get_percent(fdf->height, 45);
}
