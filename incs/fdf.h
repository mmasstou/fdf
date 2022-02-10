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

# define ALPHA .785398163397448
# define BETA .785398163397448






# define HEIGHT			1180
# define WIDTH			2020
# define ALTITUDE 1
# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SUCCUSS 0
# define ERROR -1


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
void	my_mlx_pixel_put(fdf *data, int x, int y, int color);
void	draw_map(fdf *fdf);
int	ft_movekey(int key, fdf *m_size);


// error 
void	h_error(void);

// init
void	img_init(t_data_img *map_data);


// windows tools 
void	ft_swap(int *x, int *y);
void	ft_trid(int *x, int *y, int z);

#endif
