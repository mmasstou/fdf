/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:00:27 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 10:00:30 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	translate(int key, t_fdf *data)
{
	if (key == UP)
		data->pad_h -= 10 ;
	if (key == DOWN)
		data->pad_h += 10;
	if (key == RIGHT)
		data->pad_w += 10;
	if (key == LIFT)
		data->pad_w -= 10;
}
