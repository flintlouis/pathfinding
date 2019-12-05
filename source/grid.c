#include "pathfinding.h"

void		load_grid_info(t_mlx *mlx)
{
	char *line;
	int fd = open(mlx->file, O_RDWR | O_CREAT);

	mlx->saved = MEM(t_saved);
	ft_get_next_line(fd, &line);
	mlx->saved->width = ft_atoi(line);
	free(line);
	ft_get_next_line(fd, &line);
	mlx->saved->height = ft_atoi(line);
	free(line);
	mlx->saved->grid = (int**)ft_memalloc(sizeof(int*) * mlx->saved->height);
	for (int x = 0; x < mlx->saved->height; x++) {
		ft_get_next_line(fd, &line);
		mlx->saved->grid[x] = (int*)ft_memalloc(sizeof(int) * mlx->saved->width);
		for (int y = 0; y < mlx->saved->width; y++) {
			if (line[y] == 'S') {
				mlx->saved->s = (t_point){y,x};
				mlx->saved->grid[x][y] = 0;
			}
			else if (line[y] == 'E') {
				mlx->saved->e = (t_point){y,x};
				mlx->saved->grid[x][y] = 0;
			}
			else
				mlx->saved->grid[x][y] = line[y] - 48;
		}
		free(line);
	}
	close(fd);
}

void		save_grid(t_mlx *mlx)
{
	char *size;
	size_t len;
	int fd = open(mlx->file, O_RDWR | O_CREAT, 0666);

	size = ft_itoa(GRID_COL);
	len = ft_strlen(size);
	write(fd, size, len);
	write(fd, "\n", 1);
	free(size);
	size = ft_itoa(GRID_ROWS);
	len = ft_strlen(size);
	write(fd, size, len);
	write(fd, "\n", 1);
	free(size);
	for (int y = 0; y < GRID_ROWS; ++y)
	{
		for (int x = 0; x < GRID_COL; ++x)
		{
			if (x == start->loc.x && y == start->loc.y)
				write(fd, "S", 1);
			else if (x == end->loc.x && y == end->loc.y)
				write(fd, "E", 1);
			else if (mlx->grid[x][y].obstacle)
				write(fd, "1", 1);
			else
				write(fd, "0", 1);				
		}
		write(fd, "\n", 1);
	}
}

void 		load_grid(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	mlx->grid = (t_node**)ft_memalloc(sizeof(t_node*) * mlx->saved->width);
	while (i < mlx->saved->width)
	{
		j = 0;
		mlx->grid[i] = (t_node*)ft_memalloc(sizeof(t_node) * mlx->saved->height);
		while (j < mlx->saved->height)
		{
			mlx->grid[i][j].loc = (t_point){i,j};
			mlx->grid[i][j].neighbors = (t_node**)ft_memalloc(sizeof(t_node*) * 8);
			mlx->grid[i][j].obstacle = mlx->saved->grid[j][i];
			j++;
		}
		i++;
	}
	start = &mlx->grid[S.x][S.y];
	end = &mlx->grid[E.x][E.y];
	start->obstacle = 0;
	end->obstacle = 0;
}

void 		generate_grid(t_mlx *mlx)
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
	start = &mlx->grid[START.x][START.y];
	end = &mlx->grid[END.x][END.y];
	start->obstacle = 0;
	end->obstacle = 0;
}
