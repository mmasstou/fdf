/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:17:44 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/25 12:49:59 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	x_button(t_fdf *fdf)
{
	(void)fdf;
	exit(EXIT_SUCCESS);
}

int	ft_close(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window(fdf->img->mlx, fdf->img->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
