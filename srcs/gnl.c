/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:32:37 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 14:32:39 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

char	*ft_gnl(int fd)
{
	int		i;
	int		n;
	char	buff[1];
	char	line[1000000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[0] = 0;
	i = 0;
	n = read(fd, buff, 1);
	while (n > 0)
	{
		line[i++] = buff[0];
		line[i] = '\0';
		if (buff[0] == '\n')
			return (ft_strdup(line));
		n = read(fd, buff, 1);
	}
	if (!line[0])
		return (NULL);
	if (buff[i] && buff[i] == '\n')
		line[i++] = '\n';
	return (ft_strdup(line));
}
