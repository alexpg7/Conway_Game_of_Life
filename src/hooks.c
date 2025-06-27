#include "conway.h"

int	exit_conway(t_vars *vars, int ex)
{
	if (vars->mlx)
	{
		if (vars->img)
			mlx_destroy_image(vars->mlx, vars->img);
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (vars->mat)
		ft_freemat(&vars->mat, -1);
	if (vars->mat2)
		ft_freemat(&vars->mat2, -1);
	exit(ex);
	return (0);
}

void	start_sim(t_vars *vars)
{
	int		l;

	l = 0;
	if (vars->n > 0 && l == 0)
	{
		ft_run(vars, &vars->n, vars->grid, &l);
	}
	if (l == 1)
		exit_conway(vars, 0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == S)
	{
		start_sim(vars);
	}
	return (0);
}