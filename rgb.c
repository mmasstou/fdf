static int	rgb_percent(int p)
{
	return ((255 * p) / 100);
}

static void	ft_puthex(unsigned int nbr, char *tab, int *i)
{
	if (nbr > 16)
	{
		ft_puthex(nbr / 16, tab, i);
		ft_puthex(nbr % 16, tab, i);
	}
	else
	{
		if (nbr < 10)
		{
			tab[*i] = nbr + 48;
			*i += 1;
		}
		else
		{
			tab[*i] = (nbr - 10) + 'a';
			*i += 1;
		}
	}
}

int	ft_rgb(int per_r, int per_g, int per_b)
{
	char	*hexc;
	int		index;
	int		red;
	int		green;
	int		blue;

	index = 0;
	hexc = (char *)malloc(14);
	if (!hexc)
		return (0);
	red = rgb_percent(per_r);
	green = rgb_percent(per_g);
	blue = rgb_percent(per_b);
	ft_puthex(red, hexc, &index);
	ft_puthex(green, hexc, &index);
	ft_puthex(blue, hexc, &index);
	hexc = ft_strjoin("0x", hexc);
	index = ft_hextoi(hexc);
	free(hexc);
	return (index);
}
