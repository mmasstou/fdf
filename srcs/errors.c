/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:41:53 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/25 09:30:02 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	h_error(void)
{
	ft_putstr_fd(strerror(errno), STDERR);
	ft_putchar_fd('\n', STDERR);
}

int	check_fd(char *filename, t_fdf *data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("No file ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd("\n", 2);
		//fdf_free(data);
		(void)data;
		exit (EXIT_FAILURE);
	}
	close(fd);
	return (1);
}

void	check_line(char *line, t_fdf *data)
{
	if (line[0] == '\n' && data->height == 0)
	{
		ft_putendl_fd("No data found", 2);
		exit(1);
	}
	if (line[0] == '\n' && data->height != 0)
		ft_error("Found wrong line length. Exiting");
}

void	fdf_error_read(t_fdf *fdf, char *message_err)
{
	ft_putendl_fd(message_err, STDERR_FILENO);
	fdf_free(fdf);
	exit(EXIT_FAILURE);
}

void	ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}
