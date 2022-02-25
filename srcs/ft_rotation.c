/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:58:52 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/25 11:54:25 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

void	rotation_x(float *y, int *z, float alpha)
{
	int	pre_y;

	pre_y = *y;
	*y = pre_y * cos(alpha) + *z * sin(alpha);
	*z = -pre_y * sin(alpha) + *z * cos(alpha);
}

void	rotation_y(float *x, int *z, float beta)
{
	int	pre_x;

	pre_x = *x;
	*x = pre_x * cos(beta) + *z * sin(beta);
	*z = -pre_x * sin(beta) + *z * cos(beta);
}

void	rotation_z(float *x, float *y, float gamma)
{
	int	pre_x;
	int	pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = pre_x * cos(gamma) - pre_y * sin(gamma);
	*y = pre_x * sin(gamma) + pre_y * cos(gamma);
}
