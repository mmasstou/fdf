#include "../incs/fdf.h"

int	ft_mousekey(int button, int x, int y, fdf *param)
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
	
	mlx_clear_window(param->img->mlx, param->img->win);
	mlx_destroy_image(param->img->mlx, param->img->img);
	param->img->img = mlx_new_image(param->img->mlx, WIDTH, HEIGHT);
	param->img->img_addr = mlx_get_data_addr(param->img->img,\
	 &param->img->bpp, &param->img->line_len, &param->img->endian);
	draw_map(param);
	mlx_put_image_to_window(param->img->mlx, param->img->win, param->img->img, 0, 0);
	print_menu(param);
	return (1);
}

int	ft_mouse_move(int x, int y, fdf *param)
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

	mlx_clear_window(param->img->mlx, param->img->win);
	mlx_destroy_image(param->img->mlx, param->img->img);
	param->img->img = mlx_new_image(param->img->mlx, WIDTH, HEIGHT);
	param->img->img_addr = mlx_get_data_addr(param->img->img,\
	 &param->img->bpp, &param->img->line_len, &param->img->endian);
	draw_map(param);
	mlx_put_image_to_window(param->img->mlx, param->img->win, param->img->img, 0, 0);
	print_menu(param);
	return (1);
}

int ft_mouse_click_up(int button, int x, int y, fdf *param)
{
	if (button == LEFT_CLICK)
		param->pos_m->click_on = false;
	(void)x;
	(void)y;
	return (1);
}