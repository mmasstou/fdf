/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:52:01 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/24 16:40:29 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"


void	colors(int key, t_fdf *data)
{
	if (key == RANDOM_COLORS)
	{
		data->colos_name = ft_strdup("Random");
		data->key = RANDOM_COLORS;
	}
	if (key == DEFAULT_COLORS)
	{
		data->colos_name = ft_strdup("Default");
		data->key = DEFAULT_COLORS;
	}
}

int	ft_color(float z, float z1, t_fdf *fdf)
{
	int	color;

	(void)fdf;
	if (fdf->key == RANDOM_COLORS)
		color = 0xFFFFFF * fabsf(fdf->zom / fdf->altitude);
	else if (fdf->key == DEFAULT_COLORS)
		color = 0xFFFFFF;
	else
		color = 0xFFFFFF;
	if (z || z1)
	{
		if (fdf->projection->parallel == true)
			return (0xfb6f1b);
		else
			return (color);
	}
	else
		return (color);
}
