#include "pathfinding.h"

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
			mlx->grid[i][j].neighbors = (t_node**)ft_memalloc(sizeof(t_node*) * 4);
			j++;
		}
		i++;
	}
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
			if (i < GRID_COL - 1)
				grid[i][j].neighbors[0] = &grid[i + 1][j];
			if (i > 0)
				grid[i][j].neighbors[1] = &grid[i - 1][j];
			if (j < GRID_ROWS - 1)
				grid[i][j].neighbors[2] = &grid[i][j + 1];
			if (j > 0)
				grid[i][j].neighbors[3] = &grid[i][j - 1];
			j++;
		}
		i++;
	}
}

void			setup_pathfinding(void)
{
	t_mlx *mlx;

	w = WIDTH / GRID_COL;
	h = HEIGHT / GRID_ROWS;
	mlx = init_mlx();
	init_grid(mlx);
	add_neighbors(mlx->grid);
	mlx->openSet = &START;
	draw_grid(mlx, (t_colour){200,200,200});
	draw_set(mlx, mlx->openSet, (t_colour){0,100,0});
	hook(mlx);
}
