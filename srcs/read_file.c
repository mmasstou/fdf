#include "../incs/fdf.h"

static int	ft_count_words(char *line,char sp)
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

static void	store_row_color(pnt *matrix, char *line)
{
	char	**split;
	int		j;
	int		i;

	j = 0;
	split = ft_split(line, ' ');

	while (split[j])
	{
		matrix[j].z = ft_atoi(split[j]);
		matrix[i].color = ft_hextoi(split[i]);
		++j;
	}
	free(split);
}

static void	store_row(pnt *matrix, char *line)
{
	char	**split;
	int		j;
	int		i;

	j = 0;
	split = ft_split(line, ' ');
	if (ft_strchr(split[j], ',') == NULL)
	{
		while (split[j])
		{
			matrix[j].z = ft_atoi(split[j]);
			++j;
		}
		free(split);
	}
	else 
		store_row_color(matrix, line);
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
		store_row(fdf->matrix[i], line);
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
	if (fd < 1)
		h_error();
	line = get_next_line(fd);
	fdf->width = ft_count_words(line, ' ');
	while (line)
	{
		line = get_next_line(fd);
		++fdf->height;
	}
	free(line);
	close(fd);
	ft_get_data(fdf, fname);
}
