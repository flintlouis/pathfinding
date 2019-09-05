
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
			put_square(mlx, (t_point){x*w, y*h}, c);
			x++;
		}
		y++;
	}
	put_square(mlx, (t_point){END.loc.x*w,END.loc.y*h}, (t_colour){c.r>>1,c.g>>1,c.b>>1});
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