/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:53:55 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 09:53:58 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	altitude(int key, fdf *data)
{
	if (key == ALTITUDE_UP)
		data->altitude += 0.3 ;
	if (key == ALTITUDE_DOWN)
		data->altitude -= 0.3;
}
