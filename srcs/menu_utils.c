/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:17:56 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/25 11:54:46 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

void	print_line(t_fdf *fdf, int y, int color, char *menu)
{
	mlx_string_put(fdf->img->mlx, fdf->img->win, 10, y, color, menu);
	free(menu);
}
