#include "pathfinding.h"

int			close_window(void *ptr)
{
	(void)ptr;
	exit(0);
	return (0);
}

int			release_key(int key, t_mlx *mlx)
{
	if (key == KEY_R)
		reset_game(mlx);
	return (0);
}

int			press_key(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		close_window(0);
	else if (key == KEY_SPACE)
		mlx->step = 1;
	return (0);
}
