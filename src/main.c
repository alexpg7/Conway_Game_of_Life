#include "conway.h"

void	ft_putstr2_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		ft_putchar_fd(' ', fd);
		i++;
	}
}

void	ft_fill(char **mat, int max)
{
	int	i;
	int	j;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			if ((i == 0 || i == max - 1) && (j == 0 || j == max - 1))
				mat[i][j] = '+';
			else if ((i == 0 || i == max - 1) && (j < max - 1 && j > 0))
				mat[i][j] = '-';
			else if ((j == 0 || j == max - 1) && (i < max - 1 && i > 0))
				mat[i][j] = '|';
			else
				mat[i][j] = ' ';
			j++;
		}
		i++;
	}
}

char *ft_freemat(char ***matrix, int size)
{
	int	i;

	i = 0;
	if (size <= 0)
	{
		while ((*matrix)[i] != NULL)
		{
			free((*matrix)[i]);
			i++;
		}
		free(*matrix);
	}
	else
	{
		while (i < size)
		{
			free((*matrix)[i]);
			i++;
		}
		free(*matrix);
	}
	return (NULL);
}

char	**ft_init(int grid)
{
	char **ptr;
	int		i;

	ptr = (char **)malloc(sizeof(char *) * (grid + 3));
	if (!ptr)
	{
		perror("malloc");
		return (NULL);
	}
	i = 0;
	while (i < grid + 2)
	{
		ptr[i] = (char *)malloc(sizeof(char) * (grid + 3));
		if (!(ptr[i]))
		{
			perror("malloc");
			return ((char **)ft_freemat(&ptr, i));
		}
		ptr[i][grid + 2] = '\0';
		i++;
	}
	ptr[grid + 2] = NULL;
	return (ptr);
}

int	main(int narg, char **argv)
{
	t_vars	vars;

	if (narg != 3)
	{
		ft_putstr_fd("Introduce a grid dimension and window resolution.\n", 1);
		return (0);
	}
	vars.grid = ft_atoi(argv[1]);
	vars.res = ft_atoi(argv[2]);
	vars.mat = ft_init(vars.grid);
	if (vars.mat == NULL)
		return (1);
	ft_fill(vars.mat, vars.grid + 2);
	ft_execute(vars.grid, &vars);
	ft_freemat(&vars.mat, -1);
	return (0);
}
