/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:29:56 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/25 11:52:36 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "fdf.h"

void	draw_map_bonus(t_fdf *fdf);
int		ft_movekey(int key, t_fdf *fdf);
void	ft_zoom_bonus(t_fdf *fdf, int _zoom, int _altitude);
void	padding_bonus(t_fdf *fdf);
char	*ft_title(char *title);
int		re_draw(t_fdf *data);
// events
int		ft_mousekey(int button, int x, int y, t_fdf *param);
int		ft_mouse_move(int x, int y, t_fdf *param);
int		ft_mouse_click_up(int button, int x, int y, t_fdf *param);
// event utils
void	rotate_x(int key, t_fdf *data);
void	rotate_y(int key, t_fdf *data);
void	rotate_z(int key, t_fdf *data);
void	translate(int key, t_fdf *data);
void	altitude(int key, t_fdf *data);
void	colors(int key, t_fdf *data);
void	defualt_projecton(t_fdf *fdf);
void	event_rotation(int key, t_fdf *fdf);
// rotation
void	rotation_x(float *y, int *z, float alpha);
void	rotation_y(float *x, int *z, float beta);
void	rotation_z(float *x, float *y, float gamma);
// print menu
void	print_menu(t_fdf *fdf);
void	print_line(t_fdf *fdf, int y, int color, char *menu);
#endif
