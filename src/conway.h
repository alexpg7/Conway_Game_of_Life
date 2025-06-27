#include "../lib/Libft/libft.h"
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

#define S 115

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		res;
	int		grid;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	**mat;
	char	**mat2;
	int		n;
}	t_vars;

int ft_execute(int grid, t_vars *vars);

int	exit_conway(t_vars *vars, int ex);

int	key_hook(int keycode, t_vars *vars);

void  ft_printgrid(t_vars *vars);

char  *ft_freemat(char ***matrix, int size);

void	ft_run(t_vars *vars, int *n, int size, int *l);

char  **ft_init(int grid);
