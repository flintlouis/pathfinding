
#include "pathfinding.h"

void	draw_grid(t_mlx *mlx, t_colour c)
{
	int x;
	int y;

	y = 0;
	while (y < GRID_ROWS)
	{
		x = 0;
		while (x < GRID_COL)
		{
			if (mlx->grid[x][y].obstacle)
				put_square(mlx, (t_point){x*w, y*h}, (t_colour){0,0,0});
			else
				put_square(mlx, (t_point){x*w, y*h}, c);
			x++;
		}
		y++;
	}
}

void draw_start_end(t_mlx *mlx, t_colour c)
{
	put_square(mlx, (t_point){start->loc.x*w, start->loc.y*h}, c);
	put_square(mlx, (t_point){end->loc.x*w, end->loc.y*h}, c);
}

void draw_path(t_mlx *mlx, t_node *path, t_colour c)
{
	t_node *tmp;
	t_point loc;

	if (!path)
		return ;
	tmp = path;
	while (tmp)
	{
		loc = (t_point){tmp->loc.x*w, tmp->loc.y*h};
		put_square(mlx, loc, c);
		tmp = tmp->prev;
	}
}

void draw_set(t_mlx *mlx, t_node *set, t_colour c)
{
	t_node *tmp;
	t_point loc;

	if (!set)
		return ;
	tmp = set;
	while (tmp)
	{
		loc = (t_point){tmp->loc.x*w, tmp->loc.y*h};
		put_square(mlx, loc, c);
		tmp = tmp->next;
	}
}
