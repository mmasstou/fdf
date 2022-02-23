/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:22:54 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 13:23:05 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	ft_count_words(char *line, char sp)
{
	char	**tab;
	int		width;

	width = 0;
	tab = ft_split(line, sp);
	while (tab[width])
	{
		free(tab[width]);
		width++;
	}
	free(tab);
	return (width);
}

static void	store_pont(t_pnt *matrix, int z, int color, int j)
{
	matrix[j].z = z;
	matrix[j].color = color;
}

static void	store_row(t_pnt *matrix, char *line)
{
	char	**split;
	char	**tab;
	int		j;

	j = 0;
	split = ft_split(line, ' ');
	while (split[j])
	{
		if (ft_strchr(split[j], ',') == NULL)
			store_pont(matrix, ft_atoi(split[j]), -1, j);
		else if (ft_strchr(split[j], ',') != NULL)
		{
			tab = ft_split(split[j], ',');
			store_pont(matrix, ft_atoi(tab[0]), ft_hextoi(tab[1]), j);
			free(tab[0]);
			free(tab[1]);
			free(tab);
		}
		free(split[j]);
		++j;
	}
	free(split);
}

static void	ft_get_data(t_fdf *fdf, char *fname)
{
	char	*line;
	int		fd;
	int		i;

	fdf->matrix = map_init(fdf);
	fd = open(fname, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		store_row(fdf->matrix[i], line);
		free(line);
		line = get_next_line(fd);
		++i;
	}
	close(fd);
	fdf->matrix[i] = NULL;
}

void	ft_readfile(t_fdf *fdf, char *fname)
{
	char	*line;
	int		fd;

	fd = open(fname, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		fdf_error_read(fdf, "No data found");
	fdf->width = ft_count_words(line, ' ');
	while (line)
	{
		check_line(line, fdf);
		free(line);
		line = get_next_line(fd);
		++fdf->height;
	}
	close(fd);
	ft_get_data(fdf, fname);
}
