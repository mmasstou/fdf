#ifndef FDF_H
# define FDF_H

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include <mlx.h>
#include <math.h>
#include <sys/errno.h>

# define  WHITE_COLOR  0xffffff
# define  RED_COLOR 0xe80c0c
#define MAX(a, b) (a > b ? a : b)
#define ABS(a) ((a < 0) ? -a : a)

# define ALPHA .8
# define BETA .8
# define TETA  (90 - ALPHA) 






# define HEIGHT		1240
# define WIDTH		2192

// # define WIDTH 1800
// # define HEIGHT 1250

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

// MOUSE EVENTS
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// ROTATION
# define RO_LIFT 2
# define RO_RIGHT 0
# define RO_UP 13
# define RO_DOWN 1




// ZOOM
# define MAX_ZOM 4.00
# define MIN_ZOM 1.00

typedef struct s_pnt
{
	int	z;
	int color;
} pnt;

typedef struct	data_img
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		line_len;
	int		bpp;
	int		endian;
}				t_data_img;

typedef struct s_fdf
{
	int height;
	int width;
	
	int win_w;
	int win_h;

	int pad_w;
	int pad_h;

	float zom;
	float altitude;
	float alpha;

	pnt **matrix;
	t_data_img *img;
} fdf ;

typedef struct store_data
{
	fdf *map_data;
	char *str;
	int x;
	int y;
	int	fd;
}	store_data;

// srcs:
void	ft_readfile(fdf *fdf, char *fname);
void	ft_drow_line(float x, float y, float x1, float y1, fdf *data);
int		deal_key(int key, fdf *param);
int    ft_hextoi(const char *str);
char 	*ft_gnl(int fd);
void	ft_drawline(fdf *map, int x, int y, int color);
void	draw_map(fdf *fdf);
int	ft_movekey(int key, fdf *m_size);


// error 
void	h_error(void);

// init
void	img_init(t_data_img *map_data);


// windows tools 
void	ft_zoom(fdf *data);
void	ft_padding(fdf *map_data);
void	ft_swap(int *x, int *y);
int 	ft_color(float z, float z1);
char	*ft_title(char *title);
void	ft_win_resolution(fdf *map_data);
void	ft_mange_win(char *argv1, fdf *map_data);
void	ft_trid(float *x, float *y, int z, fdf *data);
// BONUS PART
int	ft_movekey(int key, fdf *m_size);
int	ft_mousekey(int button, int x, int y, fdf *param);
#endif
