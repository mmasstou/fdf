/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:08:19 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/23 16:08:21 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	fdf_free(t_fdf *fdf)
{
	free(fdf->colos_name);
	free(fdf->projection_name);
	free(fdf->title);
	free(fdf->matrix);
	free(fdf->def);
	free(fdf->pos_m);
	free(fdf->pixel);
	free(fdf->projection);
	img_free(fdf->img);
}

void	img_free(t_data_img *img)
{
	free(img->mlx);
	free(img->win);
	free(img->img);
	free(img->img_addr);
	free(img);
}
