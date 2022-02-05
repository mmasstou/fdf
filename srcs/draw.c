#include "../incs/fdf.h"

void    ft_bresenham(fdf *m_size, int i, int j, int i1, int j1)
{
    float di;
    float dj;
    int Val;
    int z;
    int z1;
   

    

    
    //zoom
    i *= m_size->zom;
    j *= m_size->zom;
    i1 *= m_size->zom;
    j1 *= m_size->zom;
    
    
    // m_size->color = (z) ? 0xe80c0c : 0xffffff; 
    

    i += m_size->pad_h;
    j += m_size->pad_w;
    i1 += m_size->pad_h;
    j1 += m_size->pad_w;
    
    
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
		my_mlx_pixel_put(m_size, i, j,m_size->matrix[i][j].color);
        // mlx_pixel_put(m_size->mlx_ptr, m_size->win_ptr, i, j, m_size->color);
        i += di;
        j += dj;
        //printf("%d - %d\n", i , j);
    }
    //printf("%d - %d(colon)\n", m_size->line_num, m_size->column_num);
    //printf("%d(j) - %d(i) - %d\n", a, b, m_size->map[a][b].z);
}

void    draw(fdf  *m_size)
{
	int i;
	int j;

	i = 0;
    while (i < m_size->height)
    {
        j = 0;
        while (j <= m_size->width)
        {
            if (j < m_size->width)
                ft_bresenham(m_size, j, i, j + 1, i); 
            if (i < m_size->height - 1)
                ft_bresenham(m_size, j, i, j, i + 1);
            j++;   
        }
        i++;
    }
}