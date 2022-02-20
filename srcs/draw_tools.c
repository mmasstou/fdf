/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:09:16 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/20 20:09:20 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

char	*ft_title(char *title)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(title, '/');
	split = ft_split(split[1], '.');
	while (split[0][i])
	{
		split[0][i] = ft_toupper(split[0][i]);
		i++;
	}
	return (split[0]);
}
