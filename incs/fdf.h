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
# define MAX(x, y)(x > y) ? x:y
# define MDUL(index) (index >= 0) ? index:-index
# define ZOOM(height) (height > 100) ? 3:18

# define HEIGHT			1080
# define WIDTH			1920

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
	int zom;
	pnt **matrix;
	t_data_img img;
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


// error 
void	h_error(void);

#endif
