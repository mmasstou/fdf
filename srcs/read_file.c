#include "../incs/fdf.h"

int	ft_count_words(char *line,char sp)
{
	char	**tab;
	int		width;

	width = 0;
	tab = ft_split(line, sp);
	while (*tab)
	{
		width++;
		tab++;
	}
	return (width);
}

static void	store_row(pnt *matrix, char *line)
{
	char	**split;
	char	**tab;
	int		j;

	j = 0;
	split = ft_split(line, ' ');
	
	while (split[j])
	{
		if (ft_strchr(split[j], ',') == NULL)
		{
			matrix[j].z = ft_atoi(split[j]);
			matrix[j].color = -1;
		}
		else if (ft_strchr(split[j], ',') != NULL)
		{
			tab = ft_split(split[j], ',');
			matrix[j].z = ft_atoi(tab[0]);
			matrix[j].color = ft_hextoi(tab[1]);
			free(tab);
		}
		++j;
	}
	free(split);
}



static void	ft_get_data(fdf *fdf, char *fname)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fdf->matrix = (pnt **)malloc(sizeof(pnt *) * (fdf->height + 1));
	while (i < fdf->height)
		fdf->matrix[i++] = (pnt *)malloc(sizeof(pnt) * (fdf->width + 1));
	fd = open(fname, O_RDONLY);
	if (fd < 1)
		h_error();
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		store_row(fdf->matrix[i                                                                                                                               ], line);
		line = get_next_line(fd);
		++i;
	}
	free(line);
	close(fd);
	fdf->matrix[i] = NULL;
}

void	ft_readfile(fdf *fdf, char *fname)
{
	char	*line;
	int		fd;

	fd = open(fname, O_RDONLY);
	line = get_next_line(fd);
	fdf->width = ft_count_words(line, ' ');
	while (line)
	{
		check_line(line, fdf);
		line = get_next_line(fd);
		++fdf->height;
	}
	free(line);
	close(fd);
	ft_get_data(fdf, fname);
}
