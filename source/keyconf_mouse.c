#include "pathfinding.h"

static t_node *search_node(t_mlx *mlx, int x, int y)
{
	t_node *open;
	t_node *closed;

	open = mlx->openSet;
	closed = mlx->closedSet;
	while (open || closed)
	{
		if (open && open->loc.x == x && open->loc.y == y) {
			ft_putendl("OpenSet:");
			return (open);
		}
		else if (closed && closed->loc.x == x && closed->loc.y == y) {
			ft_putendl("ClosedSet:");
			return (closed);
		}
		if (open)
			open = open->next;
		if (closed)
			closed = closed->next;
	}
	return (NULL);
}

static void get_node_info(t_mlx *mlx, int x, int y)
{
	int i;
	int j;
	t_node *node;

	i = x / w;
	j = y / h;
	system("clear");
	node = search_node(mlx, i, j);
	if (!node)
		ft_putendl("No Set");
	else {
		printf("Loc  : (%d, %d)\nF    : %.2f\nG    : %.2f\nH    : %.2f\n",
		node->loc.x, node->loc.y, node->f, node->g, node->h);
		if (node->prev)
			printf("Prev : (%d, %d)\n", node->prev->loc.x, node->prev->loc.y);
		else
			ft_putendl("Prev : (NULL)");
	}
}

int				mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (button == L_MOUSE)
		get_node_info(mlx, x, y);
	return (0);
}
