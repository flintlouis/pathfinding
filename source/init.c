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

static void hook(t_mlx *mlx)
{
	mlx_loop_hook(mlx->mlx, pathfinding, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, mouse_press, mlx);
	mlx_hook(mlx->win, 5, 1L << 3, mouse_release, mlx);
	mlx_hook(mlx->win, 6, 1L << 6, mouse_move, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, press_key, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, release_key, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, close_window, NULL);
	mlx_loop(mlx->mlx);
}

static void init_grid(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	mlx->grid = (t_node**)ft_memalloc(sizeof(t_node*) * GRID_COL);
	while (i < GRID_COL)
	{
		j = 0;
		mlx->grid[i] = (t_node*)ft_memalloc(sizeof(t_node) * GRID_ROWS);
		while (j < GRID_ROWS)
		{
			mlx->grid[i][j].loc = (t_point){i,j};
			mlx->grid[i][j].neighbors = (t_node**)ft_memalloc(sizeof(t_node*) * 8);
			if (((rand() % 100) / 10.0) < OBSTACLES)
				mlx->grid[i][j].obstacle = 1;
			j++;
		}
		i++;
	}
	START.obstacle = 0;
	END.obstacle = 0;
}

static void add_neighbors(t_node **grid)
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

static void init_openSet(t_mlx *mlx)
{
	mlx->openSet = &START;
	mlx->openSet->h = heuristic(&START, &END);
	mlx->openSet->f = mlx->openSet->h + mlx->openSet->g;
}

static void free_grid(t_node **grid)
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

static void init_pathfinding(t_mlx *mlx)
{
	init_grid(mlx);
	add_neighbors(mlx->grid);
	init_openSet(mlx);
	draw_grid(mlx, (t_colour){200,200,200});
	draw_start_end(mlx, (t_colour){46, 149, 168});
}

void reset_game(t_mlx *mlx)
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

void			setup_pathfinding(void)
{
	t_mlx *mlx;

	srand(time(0));
	w = WIDTH / GRID_COL;
	h = HEIGHT / GRID_ROWS;
	mlx = init_mlx();
	init_pathfinding(mlx);
	hook(mlx);
}
