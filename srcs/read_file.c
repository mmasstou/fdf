/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:22:54 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/25 12:48:01 by mmasstou         ###   ########.fr       */
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
		if (ft_strncmp(tab[width], "\n", 1) == 0)
			break ;
		width++;
	}
	free(tab);
	return (width);
}

static void	store_pont(t_pnt *matrix, char *z, char *color, int j)
{
	if (!color)
	{
		matrix[j].z = 0;
		if (ft_strlen(z) < 3)
			matrix[j].color = 0;
		else
		{
			if (ft_strncmp(z, "0x", 2) == 0 || ft_strncmp(z, "0X", 2) == 0)
				matrix[j].color = ft_hextoi(z);
			else
				matrix[j].color = ft_atoi(z);
		}
		free(z);
	}
	else
	{
		matrix[j].z = ft_atoi(z);
		if (ft_strncmp(color, "0x", 2) == 0 || ft_strncmp(color, "0X", 2) == 0)
			matrix[j].color = ft_hextoi(color);
		else
			matrix[j].color = ft_atoi(color);
	}
}

static int	store_row(t_pnt *matrix, char *line)
{
	char	**split;
	char	**tab;
	int		j;

	j = 0;
	split = ft_split(line, ' ');
	while (split[j])
	{
		if (!ft_strncmp(split[j], "\n", ft_strlen(split[j])))
			break ;
		if (ft_strchr(split[j], ',') == NULL)
			store_pont(matrix, split[j], "0xFFFFFF", j);
		else if (ft_strchr(split[j], ',') != NULL)
		{
			tab = ft_split(split[j], ',');
			store_pont(matrix, tab[0], tab[1], j);
			free(tab[0]);
			free(tab[1]);
			free(tab);
		}
		free(split[j]);
		++j;
	}
	free(split);
	return (j);
}

static void	ft_get_data(t_fdf *fdf, char *fname)
{
	char	*line;
	int		fd;
	int		i;
	int		line_size;

	fdf->matrix = map_init(fdf);
	fd = open(fname, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		line_size = store_row(fdf->matrix[i], line);
		if (line_size < fdf->width)
			ft_error("Found wrong line length. Exiting");
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
		ft_error("No data found");
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
