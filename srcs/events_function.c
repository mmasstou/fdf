/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:56:20 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 09:56:23 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	ft_movekey(int key, fdf *m_size)
{
	if (key == 53)
	{
		mlx_destroy_window(m_size->img->mlx, m_size->img->win);
		exit(0);
	}
	translate(key, m_size);
	altitude(key, m_size);
	colors(key, m_size);
	rotate_x(key, m_size);
	rotate_y(key, m_size);
	rotate_z(key, m_size);
	re_draw(m_size);
	return (0);
}

int	ft_mousekey(int button, int x, int y, fdf *param)
{
	if (button == SCROLL_UP)
		param->zom += 0.65;
	if (button == SCROLL_DOWN)
		param->zom -= 0.63;
	if (button == LEFT_CLICK)
	{
		param->pos_m->click_on = true;
		param->pos_m->prev_x = x;
		param->pos_m->prev_y = y;
	}
	re_draw(param);
	return (1);
}

int	ft_mouse_move(int x, int y, fdf *param)
{
	if (param->pos_m->click_on == true)
	{
		param->pad_w += (x - param->pos_m->prev_x);
		param->pad_h += (y - param->pos_m->prev_y);
		param->pos_m->prev_x = x;
		param->pos_m->prev_y = y;
	}
	else
	{
		param->pos_m->x = 0;
		param->pos_m->y = 0;
	}
	re_draw(param);
	return (1);
}

int	ft_mouse_click_up(int button, int x, int y, fdf *param)
{
	if (button == LEFT_CLICK)
		param->pos_m->click_on = false;
	(void)x;
	(void)y;
	return (1);
}
