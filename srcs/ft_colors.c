/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:52:01 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 09:52:05 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static int	rgb_percent(int p)
{
	return ((255 * p) / 100);
}

static void	ft_puthex(unsigned int nbr, char *tab, int *i)
{
	if (nbr > 16)
	{
		ft_puthex(nbr / 16, tab, i);
		ft_puthex(nbr % 16, tab, i);
	}
	else
	{
		if (nbr < 10)
		{
			tab[*i] = nbr + 48;
			*i += 1;
		}
		else
		{
			tab[*i] = (nbr - 10) + 'a';
			*i += 1;
		}
	}
}

int	ft_rgb(int per_r, int per_g, int per_b)
{
	char	*hexc;
	int		index;
	int		red;
	int		green;
	int		blue;

	index = 0;
	hexc = (char *)malloc(14);
	if (!hexc)
		return (0);
	red = rgb_percent(per_r);
	green = rgb_percent(per_g);
	blue = rgb_percent(per_b);
	ft_puthex(red, hexc, &index);
	ft_puthex(green, hexc, &index);
	ft_puthex(blue, hexc, &index);
	hexc = ft_strjoin("0x", hexc);
	index = ft_hextoi(hexc);
	free(hexc);
	return (index);
}

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
		return (color);
	else
		return (color);
}
