/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:56:20 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/25 12:13:19 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

static	void	projct_type(t_fdf *fdf, bool iso, bool parallel)
{
	fdf->projection->iso = iso;
	fdf->projection->parallel = parallel;
	if (iso == true)
		fdf->projection_name = "ISOMITRIC";
	else
		fdf->projection_name = "PARALLEL";
}

int	ft_movekey(int key, t_fdf *m_size)
{
	if (key == DEF)
		defualt_projecton(m_size);
	if (key == 53)
	{
		mlx_destroy_window(m_size->img->mlx, m_size->img->win);
		exit(0);
	}
	if (key == ISO)
		projct_type(m_size, true, false);
	if (key == PARALL)
		projct_type(m_size, false, true);
	translate(key, m_size);
	altitude(key, m_size);
	colors(key, m_size);
	event_rotation(key, m_size);
	re_draw(m_size);
	return (0);
}

int	ft_mousekey(int button, int x, int y, t_fdf *param)
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

int	ft_mouse_move(int x, int y, t_fdf *param)
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

int	ft_mouse_click_up(int button, int x, int y, t_fdf *param)
{
	if (button == LEFT_CLICK)
		param->pos_m->click_on = false;
	(void)x;
	(void)y;
	return (1);
}
