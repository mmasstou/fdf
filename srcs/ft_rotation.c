#include "../incs/fdf.h"

void	rotate_x(float *y, float *z, double alpha)
{
	int previous_y;
	printf("----------+ rotate_x\n");

	previous_y = *y;
	*y = *y * cos(alpha) + *z * sin(alpha);
	*z = -*y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(float *x, float *z, double beta)
{
	int previous_x;
	printf("----------+ rotate_y\n");

	previous_x = *x;
	*x = *x * cos(beta) + *z * sin(beta);
	*z = -*x * sin(beta) + *z * cos(beta);
}

void	rotate_z(float *x, float *y, double alpha)
{
	printf("----------+ rotate_z\n");
	int previous_y;
	int previous_x;

	previous_x = *x;
	previous_y = *y;
	*x = *x * cos(alpha) + *y * sin(alpha);
	*y = *y * cos(alpha) + *x * sin(alpha);
}
