#include "../incs/fdf.h"

void	ft_swap(int *x, int *y)
{
	float	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}