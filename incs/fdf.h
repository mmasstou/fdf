/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:10:02 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/25 12:23:45 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <sys/errno.h>
# include <stdbool.h> 
# include "keys.h"

# define  WHITE_COLOR  0xffffff
# define  RED_COLOR 0xe80c0c

# define HEIGHT		1240
# define WIDTH		2192

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_pnt
{
	int	z;
	int	color;
}	t_pnt;

typedef struct projection
{
	bool	iso;
	bool	parallel;
}	t_proj;
typedef struct data_img
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		line_len;
	int		bpp;
	int		endian;
}				t_data_img;

typedef struct def
{
	int	zoom;
	int	pad_w;
	int	pad_h;
	int	altitude;
}	t_default;
typedef struct mouse
{
	int		prev_x;
	int		prev_y;
	int		x;
	int		y;
	bool	click_on;
}	t_mouse;

typedef struct pixel
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	int		z;
	int		z1;
	int		color;
}		t_pixel;

typedef struct s_fdf
{
	int			height;
	int			width;
	char		*title;
	int			win_w;
	int			win_h;
	int			pad_w;
	int			pad_h;
	float		zom;
	float		altitude;
	float		alpha;
	float		beta;
	float		gama;
	char		*colos_name;
	char		*projection_name;
	int			key;
	bool		color_auto;
	t_default	*def;
	t_mouse		*pos_m;
	t_pixel		*pixel;
	t_pnt		**matrix;
	t_data_img	*img;
	t_proj		*projection;

}	t_fdf;

// srcs:
void	pixel_manage(int x, int y, t_fdf *fdf, char c);
void	ft_readfile(t_fdf *fdf, char *fname);
int		ft_hextoi(const char *str);
void	ft_drawline(t_fdf *map, int x, int y, int color);
int		ft_count_words(char *line, char sp);
// init
void	img_init(t_data_img *map_data);
t_fdf	*data_init(void);
t_pnt	**map_init(t_fdf *fdf);

// windows tools 
void	resolution(t_fdf *map_data);
// events 
int		x_button(t_fdf *fdf);
int		ft_close(int key, t_fdf *fdf);
// colors
int		ft_color(float z, float z1, t_fdf *fdf);
// errors
int		check_fd(char *filename, t_fdf *data);
void	check_line(char *line, t_fdf *data);
void	h_error(void);
void	ft_error(char *s);
// free
void	fdf_free(t_fdf *fdf);
void	img_free(t_data_img *img);
void	fdf_error_read(t_fdf *fdf, char *message_err);
#endif
