#include "../incs/fdf.h"

void	my_mlx_pixel_put(fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_data + (y * data->size_width + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
int		deal_key(int key, fdf *param)
{
	void	*hf;
	printf("%d\n",key);
	hf = param->mlx;
	return (key);
}

void    ft_bresenham(fdf *m_size, int i, int j, int i1, int j1)
{
    float di;
    float dj;
    int Val;
    int colxor;

   

    

    
    //zoom
    i *= m_size->zom;
    j *= m_size->zom;
    i1 *= m_size->zom;
    j1 *= m_size->zom;
    
    
    // colxor = (color) ? 0xe80c0c : 0xffffff; 
    colxor = 0xffffff; 
    
	// color = m_size->matrix[i][j].color;
    // i += m_size->pad_h;
    // j += m_size->pad_w;
    // i1 += m_size->pad_h;
    // j1 += m_size->pad_w;
    
    
    di = i1 - i;
    dj = j1 - j;

    Val = MAX(MDUL(di), MDUL(dj));
    
    di /= Val;
    dj /= Val;
    //printf("%f - %f\n", di, dj);
    // m_size->map[i1][j1]->color;
    
    while ((int)(i - i1) || (int)(j - j1))
    {
        //m_size->color = (( m_size ) == 1) ? 0xe80c0c : 0xffffff;
		my_mlx_pixel_put(m_size, i, j,colxor);
        // mlx_pixel_put(m_size->mlx_ptr, m_size->win_ptr, i, j, m_size->color);
        i += di;
        j += dj;
        // printf("%d - %d\n", i , j);
    }
    //printf("%d - %d(colon)\n", m_size->line_num, m_size->column_num);
    //printf("%d(j) - %d(i) - %d\n", a, b, m_size->map[a][b].z);
}

int main(int argc, char *argv[])
{
	fdf	*map_data;
	char	**title;
	int	x ;
	int	y;
	// int	x1;
	// int	y1;



	map_data = (fdf *)malloc(sizeof(fdf));
	if (!map_data)
		return (0);
	if (argc == 2)
		ft_readfile(map_data, argv[1]); 
	
	map_data->endian = 0;
	map_data->win_h = (HEIGHT)  ;
	map_data->win_w = (WIDTH);
	title = ft_split(argv[1], '/');
	title = ft_split(title[1], '.');

	// image config
	map_data->size_width = 1920 * 4;
	map_data->bpp = 32;
	map_data->mlx = mlx_init();

	// windows config
	map_data->win_h += (map_data->win_h / 10);
	map_data->win_w += (map_data->win_w / 10);


	map_data->win = mlx_new_window(map_data->mlx, map_data->win_w, map_data->win_h , title[0]);
	map_data->img = mlx_new_image( map_data->mlx, map_data->win_w, map_data->win_h);
	map_data->img_addr =  mlx_get_data_addr(map_data->img, &map_data->bpp, &map_data->size_width, &map_data->endian);

	map_data->zom = ZOOM(map_data->height);

	map_data->pad_w = ((map_data->win_w / 2)) - ((map_data->width / 2));
	map_data->pad_h = ((map_data->win_h / 2)) - ((map_data->height / 2));

	y = 0;
	while (y < map_data->height )
	{
		x = 0;
		while (x < map_data->width)
		{
			printf("**++**%d - ***++**%d\n", x , y);
			if (x < map_data->width)
                ft_bresenham(map_data, x, y, x + 1, y); 
            if (y < map_data->height - 1)
                ft_bresenham(map_data, x, y, x, y + 1);
			//("**++**%d - ***++**%d --> %d\n", x , y);
			// my_mlx_pixel_put(map_data,(x * map_data->zom) ,(y * map_data->zom) ,map_data->matrix[y][x].color);
			x++;
		}
		printf("\n");
		y++;
	}
	mlx_put_image_to_window(map_data->mlx, map_data->win, map_data->img, 0, 0);
	
	// red_map(24, 35, 12,20,map_data);
	mlx_key_hook(map_data->win,deal_key, map_data);
	mlx_loop(map_data->mlx);

	return (0);
}