/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:14:23 by mmasstou          #+#    #+#             */
/*   Updated: 2022/02/21 13:14:25 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	ft_islower(int l)
{
	return (l >= 'a' && l <= 'z');
}

void	m_alpha(int *result, char str)
{
	if (ft_islower(str))
		*result = *result * 16 + str + 10 - 'a';
	else
		*result = *result * 16 + str + 10 - 'A';
}

int	ft_hextoi(const char *str)
{
	int	var[2];

	var[0] = 1;
	var[1] = 0;
	str += 2;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			var[0] = -var[0];
		str++;
	}
	while (*str && ft_isalnum(*str))
	{
		if (ft_isalpha(*str))
			m_alpha(&var[1],*str);
		else
			var[1] = var[1] * 16 + *str - 48;
		str++;
	}
	return (var[1] *= var[0]);
}
