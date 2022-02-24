#include "../incs/fdf.h"

int	x_button(t_fdf *fdf)
{
	(void)fdf;
    exit(0);
}

int	ft_close(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window(fdf->img->mlx, fdf->img->win);
		exit(0);
	}
	return (0);
}