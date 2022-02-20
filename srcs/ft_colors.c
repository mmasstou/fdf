#include "../incs/fdf.h"

int	rgb_percent(int p)
{
	return ((255 * p) / 100);
}

void	ft_puthex(unsigned int nbr, char *hex)
{
	int i;

	if (nbr > 16)
	{
		ft_puthex(nbr / 16, hex);
		ft_puthex(nbr % 16, hex);
	}
	else
	{
		i  = 0;
		if (nbr > 10)
			hex[i] = nbr + 48 ;
		else 
			hex[i] = (nbr - 10) + 'a';
		i++;
		hex[i] = '\0';
	}
}

int	ft_colors(t_color color)
{
	char *hex;
	char *hexc;
	int r;
	int g;
	int b;

	r = rgb_percent(color.r);
	g = rgb_percent(color.g);
	b = rgb_percent(color.b);
	ft_puthex(r, hexc);
	hex = ft_strdup(hexc);  // r
	ft_puthex(g, hexc);
	hex = ft_strjoin(hex, hexc); // g
	ft_puthex(b, hexc);
	hex = ft_strjoin(hex, hexc);  // b

	return (ft_hextoi(hex));
}
