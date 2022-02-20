#include "../incs/fdf.h"

static int	ft_isspace(int s)
{
	char	*space;

	space = "\f\n\r\t\v ";
	while (*space)
		if (s == *space++)
			return (1);
	return (0);
}

// static int ft_is_hex_alph(int l)
// {
// 	return (l >= 'a'|| l >= 'A'|| l <= 'b' || l <= 'B' ||l <= 'c' ||  l <= 'C' || l <= 'd' ||l <= 'D' || l <= 'e' ||  l <= 'E' || l <= 'f' || l <= 'F');
// }


static int ft_islower(int l)
{
	return (l >= 'a'&& l <= 'z');
}

static int ft_isupper(int l)
{
	return (l >= 'A'&& l <= 'Z');
}
int    ft_hextoi(const char *str)
{
    int    signe;
    int    result;

    signe = 1;
    result = 0;
    str += 2;
    while (ft_isspace(*str))
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            signe = -signe;
        str++ ;
    }
    while (*str && ft_isalnum(*str))
    {
        if (ft_isalpha(*str))
        {
            if (ft_islower(*str))
                result = result * 16 + *str + 10  - 'a';
            else if (ft_isupper(*str))
                result = result * 16 + *str + 10  - 'A';
        }
        else if (ft_isdigit(*str))
            result = result * 16 + *str - 48;
		else
		{
			ft_putstr_fd("Found wrong Color. Exiting\n",2);
			exit(1);
		}
        str++;
    }
    result *= signe;
    return (result);
}