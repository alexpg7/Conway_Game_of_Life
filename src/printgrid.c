#include "conway.h"

void	pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + y * vars->line_length + x * vars->bits_per_pixel / 8;
	*(unsigned int *)dst = color;
}

void	ft_printgrid(t_vars *vars)
{
	int	x;
	int	y;
	int	res;

	res = vars->res;
	x = 0;
	while (x < res)
	{
		y = 0;
		while (y < res)
		{
			if (vars->mat[(vars->grid * x) / res + 1][(vars->grid * y) / res + 1] == 'X')
				pixel_put(vars, x, y, 0xFFFFFF);
			else
				pixel_put(vars, x, y, 0x000000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}