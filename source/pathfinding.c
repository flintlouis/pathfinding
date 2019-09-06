#include "pathfinding.h"

double heuristic(t_node *a, t_node *b)
{
	double d;
	double dx;
	double dy;

	dx = (double)b->loc.x - a->loc.x;
	dy = (double)b->loc.y - a->loc.y;
	d = sqrt(((dx*dx)+(dy*dy))); /* Euclidian distance */
	// d = abs(a->loc.x - b->loc.x) + abs(a->loc.y - b->loc.y); /* Taxi distance */
	return (d);
}

static void update_node(t_node *neighbor, t_node *node, double g, t_node *end)
{
	neighbor->g = g;
	neighbor->h = heuristic(neighbor, end);
	neighbor->f = neighbor->g + neighbor->h;
	neighbor->prev = node;

}

static int check_diag(t_node *neighbor, t_node *node)
{
	int dx;
	int dy;

	dx = neighbor->loc.x - node->loc.x;
	dy = neighbor->loc.y - node->loc.y;
	if (dx != 0 && dy != 0)
		return (1);
	return (0);
}

static void add_to_openSet(t_node *node, t_node **openSet, t_node **closedSet, t_node *end)
{
	t_node **nbs = node->neighbors;
	int i = 0;
	double tmpG;

	while (i < 8)
	{
		if (nbs[i] && !in_set(closedSet, nbs[i]))
		{
			tmpG = check_diag(nbs[i], node) ? (node->g + 1.4) : (node->g + 1);
			if (in_set(openSet, nbs[i]))
			{
				if (tmpG < nbs[i]->g)
					update_node(nbs[i], node, tmpG, end);
			}
			else
			{
				update_node(nbs[i], node, tmpG, end);
				add_node(openSet, nbs[i]);
			}
		}
		i++;
	}
}

static void find_path(t_node **openSet, t_node **closedSet, t_node **path, t_node *end)
{
	t_node *tmp;
	t_node *node;

	node = *openSet;
	tmp = *openSet;
	while (tmp)
	{
		if (tmp->f < node->f)
			node = tmp;
		tmp = tmp->next;
	}
	rm_node(openSet, node);
	add_node(closedSet, node);
	if (compare_nodes(node, end))
	{
		*path = node;
		system("clear");
		ft_putendl("Path found");
		return ;
	}
	*path = node;
	add_to_openSet(node, openSet, closedSet, end);
}

int			pathfinding(t_mlx *mlx)
{
	mlx->step = 1; /* Turn off to go step by step with spacebar */
	if (mlx->step)
	{
		if (mlx->openSet && !compare_nodes(mlx->path, &END))
		{
			find_path(&mlx->openSet, &mlx->closedSet, &mlx->path, &END);
			draw_set(mlx, mlx->openSet, (t_colour){218, 247, 166});
			draw_set(mlx, mlx->closedSet, (t_colour){144, 12, 63});
			draw_path(mlx, mlx->path, (t_colour){46, 86, 168});
			draw_start_end(mlx, (t_colour){46, 149, 168});
		}
		else if (!compare_nodes(mlx->path, &END) && !mlx->no_path)
		{
			system("clear");
			ft_putendl("No path found");
			mlx->no_path = 1;
		}
		mlx->step = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
	return (0);
}
