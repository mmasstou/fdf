#include "../incs/fdf.h"

void	ft_swap(int *x, int *y)
{
	float	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

char	*ft_title(char *title)
{
	int 	i;
	char	**split;

	i = 0;
	split = ft_split(title, '/');
	split = ft_split(split[1],'.');
	while (split[0][i])
	{
		split[0][i] = ft_toupper(split[0][i]);
		i++;
	}
	//split[0] = ft_strjoin("graphics programming : ",split[0]);
	return (split[0]);
}