#include "pathfinding.h"
# include <time.h>

static t_mlx	*init_mlx(void)
{
	t_mlx *mlx;

	mlx = MEM(t_mlx);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "A*");
	mlx->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	(mlx->data_addr = mlx_get_data_addr(mlx->image, &(mlx->bits_per_pixel),
	&(mlx->size_line), &(mlx->endian)));
	return (mlx);
}

static void		hook(t_mlx *mlx)
{
	mlx_loop_hook(mlx->mlx, pathfinding, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, mouse_press, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, press_key, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, release_key, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, close_window, NULL);
	mlx_loop(mlx->mlx);
}

static void 	add_neighbors(t_node **grid)
{
	int i;
	int j;

	i = 0;
	while (i < GRID_COL)
	{
		j = 0;
		while (j < GRID_ROWS)
		{
			if (i < GRID_COL - 1 && !grid[i + 1][j].obstacle)
				grid[i][j].neighbors[0] = &grid[i + 1][j];
			if (i > 0 && !grid[i - 1][j].obstacle)
				grid[i][j].neighbors[1] = &grid[i - 1][j];
			if (j < GRID_ROWS - 1 && !grid[i][j + 1].obstacle)
				grid[i][j].neighbors[2] = &grid[i][j + 1];
			if (j > 0 && !grid[i][j - 1].obstacle)
				grid[i][j].neighbors[3] = &grid[i][j - 1];
			if (i < GRID_COL - 1 && j > 0 && !grid[i + 1][j - 1].obstacle)
				grid[i][j].neighbors[4] = &grid[i + 1][j - 1];
			if (i > 0 && j < GRID_ROWS - 1 && !grid[i - 1][j + 1].obstacle)
				grid[i][j].neighbors[5] = &grid[i - 1][j + 1];
			if (i < GRID_COL - 1 && j < GRID_ROWS - 1 && !grid[i + 1][j + 1].obstacle)
				grid[i][j].neighbors[6] = &grid[i + 1][j + 1];
			if (i > 0 && j > 0 && !grid[i - 1][j - 1].obstacle)
				grid[i][j].neighbors[7] = &grid[i - 1][j - 1];
			j++;
		}
		i++;
	}
}

static void 	init_openSet(t_mlx *mlx)
{
	mlx->openSet = start;
	mlx->openSet->h = heuristic(start, end);
	mlx->openSet->f = mlx->openSet->h + mlx->openSet->g;
}

static void 	free_grid(t_node **grid)
{
	int i;
	int j;
	int n;

	i = 0;
	while (i < GRID_COL)
	{
		j = 0;
		while (j < GRID_ROWS)
		{
			grid[i][j].next = NULL;
			grid[i][j].prev = NULL;
			n = 0;
			while (n < 8)
			{
				grid[i][j].neighbors[n] = NULL;
				n++;
			}
			free(grid[i][j].neighbors);
			j++;
		}
		free(grid[i]);
		i++;
	}
	free(grid);
}

static void 	init_pathfinding(t_mlx *mlx)
{
	if (ft_strequ(mlx->cmd, "--load"))
		load_grid(mlx);
	else
		generate_grid(mlx);
	if (ft_strequ(mlx->cmd, "--save"))
		save_grid(mlx);
	add_neighbors(mlx->grid);
	init_openSet(mlx);
	draw_grid(mlx, (t_colour){200,200,200});
	draw_start_end(mlx, (t_colour){46, 149, 168});
}

void			reset_game(t_mlx *mlx)
{
	free_grid(mlx->grid);
	mlx->path = NULL;
	mlx->openSet = NULL;
	mlx->closedSet = NULL;
	mlx->no_path = 0;
	mlx->pause = 0;
	mlx->step = 0;
	system("clear");
	init_pathfinding(mlx);
}

void			setup_pathfinding(int argc, char **argv)
{
	t_mlx *mlx;

	srand(time(0));
	mlx = init_mlx();
	if (argc > 1) {
		mlx->cmd = argv[1];
		mlx->file = argv[2];
	}
	if (ft_strequ(mlx->cmd, "--load")) {
		load_grid_info(mlx);
		w = WIDTH / mlx->saved->width;
		h = HEIGHT / mlx->saved->height;
	}
	else {
		w = WIDTH / GRID_COL;
		h = HEIGHT / GRID_ROWS;
	}
	init_pathfinding(mlx);
	hook(mlx);
}
