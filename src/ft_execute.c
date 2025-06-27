#include "conway.h"

void	ft_initialize(char **mat, int max)
{
	int	i;
	int j;
	int	random;

	i = 1;
	srand(time(NULL));
	while (i < max + 1)
	{
		j = 1;
		while (j < max + 1)
		{
			random = rand() % 100;
			if (random < 60)
				mat[i][j] = 'X';
			j++;
		}
		i++;
	}
}

int	ft_countX(char **mat)
{
	int	i;
	int j;
	int	num;

	i = 0;
	num = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			if (mat[i][j] == 'X')
				num++;
			j++;
		}
		i++;
	}
	return (num);
}

void	ft_clonemat(char **src, char **dest)
{
	int	i;
	int	j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i][j])
		{
			dest[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

int	ft_count(char **mat, int i, int j)
{
	int	a;
	int	b;
	int	count;

	a = -1;
	count = 0;
	//printf("\n\n%i, %i:\n", i, j);
	while (a <= 1)
	{
		b = -1;
		while (b <= 1)
		{
			if (!(a == 0 && b == 0))
			{
				if (mat[i + a][j + b] == 'X')
					count++;
				//printf("%i, %i = %i\n", i + a, j + b, (mat[i+a][j+b] == 'X'));
			}
			b++;
		}
		a++;
	}
	//printf("TOT%i, %i = %i\n", i, j ,count);
	return (count);
}

char	rule(char **mat, int i, int j, int *n)
{
	int	count;
	char	m;

	count = ft_count(mat, i, j);
	m = mat[i][j];
	if (m == ' ' && count == 3)
	{
		*n = *n + 1;
		return ('X');
	}
	else if (m == 'X' && (count == 3 || count == 2))
	{
		return ('X');
	}
	else
	{
		if (m == 'X')
			*n = *n - 1;
		return (' ');
	}
}

void	ft_rules(char **end, char **start, int *n, int size, int *l)
{
	int	 i;
	int	 j;
	char	rule2;

	i = 1;
	*l = 1;
	while (i < size + 1)
	{
		j = 1;
		while (j < size + 1)
		{
			rule2 = rule(start, i, j, n);
			end[i][j] = rule2;
			if (rule2 != start[i][j])
				*l = 0;
			j++;
		}
		i++;
	}
}

void	ft_run(t_vars *vars, int *n, int size, int *l)
{
	ft_clonemat(vars->mat, vars->mat2);
	ft_rules(vars->mat, vars->mat2, n, size, l);
	ft_printgrid(vars);
}

void	ft_initmlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!(vars->mlx))
	{
		perror("mlx init");
		exit_conway(vars, 1);
	}
	vars->win = mlx_new_window(vars->mlx, vars->res, vars->res, "Conway's Game of Life");
	vars->img = mlx_new_image(vars->mlx, vars->res, vars->res);
	if (!(vars->win) || !(vars->img))
	{
		perror("mlx error");
		exit_conway(vars, 1);
	}
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	if (!(vars->addr) || !(vars->bits_per_pixel) || !(vars->line_length))
	{
		perror("mlx address get");
		exit_conway(vars, 1);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0L, exit_conway, vars);
	printf("\nPress \"S\" to run each step of the simulation.\n\n");
	printf("Click the cross to exit the program.\n\n");
	mlx_loop(vars->mlx);
}

int	ft_execute(int grid, t_vars *vars)
{
	ft_initialize(vars->mat, grid);
	vars->mat2 = ft_init(grid);
	vars->n = ft_countX(vars->mat);
	ft_initmlx(vars);
	return (0);
}
