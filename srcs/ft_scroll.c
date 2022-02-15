#include "../incs/fdf.h"

int	ft_mousekey(int button, int x, int y, fdf *param)
{
	printf("param->zom%f\n",param->zom);
	printf("button%d\n",button);
	printf("x%d\n",x);
	printf("y%d\n",y);

	if (button == SCROLL_UP)
		param->zom += 0.15;
	if (button == SCROLL_DOWN)
		param->zom -= 0.13;	
	
	mlx_clear_window(param->img->mlx, param->img->win);
	mlx_destroy_image(param->img->mlx, param->img->img);
	param->img->img = mlx_new_image(param->img->mlx, WIDTH, HEIGHT);
	param->img->img_addr = mlx_get_data_addr(param->img->img,\
	 &param->img->bpp, &param->img->line_len, &param->img->endian);
	draw_map(param);
	mlx_put_image_to_window(param->img->mlx, param->img->win, param->img->img, 0, 0);
	return (1);
}