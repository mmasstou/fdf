/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:41:53 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 12:41:56 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	h_error(void)
{
	ft_putstr_fd(strerror(errno), STDERR);
	ft_putchar_fd('\n', STDERR);
}

int	check_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("No file ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd("\n", 2);
		exit (1);
	}
	close(fd);
	return (1);
}

void	check_line(char *line, t_fdf *data)
{
	if (line[0] == '\n' && data->height == 0)
	{
		ft_putstr_fd("No data found\n", 2);
		exit(1);
	}
	else if ((data->width > ft_count_words(line, ' ')) || \
	(line[0] == '\n' && data->height != 0))
	{
		ft_putstr_fd("Found wrong line length. Exiting\n", 2);
		exit(1);
	}
}
