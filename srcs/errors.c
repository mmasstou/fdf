#include "../incs/fdf.h"

void	h_error(void)
{
	ft_putstr_fd(strerror(errno), STDERR);
	ft_putchar_fd('\n', STDERR);
}