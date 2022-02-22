/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:10:02 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 18:10:04 by mmasstou         ###   ########.fr       */
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

# define  WHITE_COLOR  0xffffff
# define  RED_COLOR 0xe80c0c

# define HEIGHT		1240
# define WIDTH		2192

// # define WIDTH 1800
// # define HEIGHT 1250

#define ISO 34
# define PARALL 35
# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SUCCUSS 0
# define ERROR -1

// ALTITUDE 
# define ALTITUDE_UP 69
# define ALTITUDE_DOWN 78
# define ALTITUDE_MIN 0.50

// ALPHA

# define ALPHA_UP 116
# define ALPHA_DOWN 121

# define BETA_UP 117
# define BETA_DOWN 115

// MOUSE EVENTS
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// keybourd events
# define LIFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
// COLORS KEY

# define RANDOM_COLORS 15
# define DEFAULT_COLORS 5

// ROTATION
// rotate_x
# define RO_X_UP 12 // Q
# define RO_X_DOWN 0 // A
// rotate_y
# define RO_Y_UP 13 // W
# define RO_Y_DOWN 1 // S
// rotate_z
# define RO_Z_UP 14 // E
# define RO_Z_DOWN 2 // D

// ZOOM
# define MAX_ZOM 4.00
# define MIN_ZOM 1.00

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
	int zoom;
	int pad_w;
	int pad_h;
	int altitude;
}	t_default;
typedef struct mouse
{
	int		prev_x;
	int		prev_y;
	int		x;
	int		y;
	bool	click_up;
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
	bool		first_click;
	bool		color_auto;
	float		*ro_x;	
	float		*ro_y;	
	float		*ro_z;
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
int		deal_key(int key, t_fdf *param);
int		ft_hextoi(const char *str);
char	*ft_gnl(int fd);
void	ft_drawline(t_fdf *map, int x, int y, int color);
void	draw_map(t_fdf *fdf);
void	draw_map_bonus(t_fdf *fdf);
int		ft_movekey(int key, t_fdf *m_size);
int		ft_count_words(char *line, char sp);
float	get_percent(int val, int perc);
// error 
void	h_error(void);

// init
void	img_init(t_data_img *map_data);
t_fdf	*data_init(void);
// print menu
void	print_menu(t_fdf *data);

// windows tools 
void	ft_zoom(t_fdf *data, int _altitude, int _zoom);
void	ft_padding(t_fdf *map_data);
char	*ft_title(char *title);
void	resolution(t_fdf *map_data);

/* BONUS PART */
int		re_draw(t_fdf *data);
// events 
int		ft_movekey(int key, t_fdf *m_size);
int		ft_mousekey(int button, int x, int y, t_fdf *param);
int		ft_mouse_move(int x, int y, t_fdf *param);
int		ft_mouse_click_up(int button, int x, int y, t_fdf *param);
// rotation
void	rotation(float *x, float *y, float z, t_fdf *data);
void	rotate_x(int key, t_fdf *data);
void	rotate_y(int key, t_fdf *data);
void	rotate_z(int key, t_fdf *data);
void	translate(int key, t_fdf *data);
// altitude
void	altitude(int key, t_fdf *data);
// colors
int		ft_rgb(int per_r, int per_g, int per_b);
int		ft_color(float z, float z1, t_fdf *fdf);
void	colors(int key, t_fdf *data);

// errors
int		check_fd(char *filename);
void	check_line(char *line, t_fdf *data);

#endif
