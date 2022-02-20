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
#include <stdbool.h>  

# define  WHITE_COLOR  0xffffff
# define  RED_COLOR 0xe80c0c
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)
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

# define BETA_UP 117
# define BETA_DOWN 115

// MOUSE EVENTS
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5


// COLORS KEY

# define RED_COLORS 15
# define BLUE_COLORS 11
# define GREEN_COLORS 5
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

typedef struct mouse
{
	int prev_x;
	int prev_y;
	int	x;
	int y;
	bool click_up;
	bool click_on;
} mouse;
typedef struct s_fdf
{
	int height;
	int width;
	char *title;
	
	int win_w;
	int win_h;

	int pad_w;
	int pad_h;

	float zom;
	float altitude;
	float alpha;
	float beta;
	float gama;
	// rotation

	char *colos;
	int		key;
	bool first_click;
	float *ro_x;	
	float *ro_y;	
	float *ro_z;
	mouse *pos_m;	

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
int	ft_count_words(char *line,char sp);

// error 
void	h_error(void);

// init
void	img_init(t_data_img *map_data);

// print menu
void	print_menu(fdf *data);

// windows tools 
void	ft_zoom(fdf *data, int _altitude, int _zoom);
void	ft_padding(fdf *map_data);
void	ft_swap(int *x, int *y);
int 	ft_color(float z, float z1 ,fdf *fdf);
char	*ft_title(char *title);
void	ft_win_resolution(fdf *map_data);
void	ft_mange_win(char **argv, int argc, fdf *map_data);
void	ft_trid(float *x, float *y,float *z, fdf *data);
// BONUS PART
int	ft_movekey(int key, fdf *m_size);
int	ft_mousekey(int button, int x, int y, fdf *param);
int	ft_mouse_move(int x, int y, fdf *param);
int ft_mouse_click_up(int button, int x, int y, fdf *param);
int ft_close(int key, fdf *param);

// angles

// void	rotate_x(float *y, float z, double alpha);
// void	rotate_y(float *x, float z, double beta);
// void	rotate_z(float *x, float *y, double alpha);


// errors
int 	check_fd(char *filename);
void	check_line(char *line, fdf *data);

#endif
