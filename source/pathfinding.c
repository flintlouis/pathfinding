#include "pathfinding.h"

static int heuristic(t_node *a, t_node *b)
{
	return (abs(a->loc.x - b->loc.x) + abs(a->loc.y - b->loc.y));
}

static void add_to_openSet(t_node *node, t_node **openSet, t_node **closedSet, t_node *end)
{
	t_node **nbs = node->neighbors;
	int i = 0;
	int tmpG;

	while (i < 4)
	{
		if (nbs[i] && !in_set(closedSet, nbs[i]))
		{
			tmpG = node->g + 1;
			if (in_set(openSet, nbs[i]))
				nbs[i]->g = tmpG < nbs[i]->g ? tmpG : nbs[i]->g;
			else
			{
				nbs[i]->g = tmpG;
				add_node(openSet, nbs[i]);
			}
			nbs[i]->h = heuristic(nbs[i], end);
			nbs[i]->f = nbs[i]->g + nbs[i]->h;
			nbs[i]->prev = node;
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
	if (compare_nodes(node, end))
	{
		*path = node;
		printf("f: %d, g : %d, h :%d\n", (*path)->f, (*path)->g, (*path)->h);
		ft_putendl("Path found");
		return ;
	}
	rm_node(openSet, node);
	add_node(closedSet, node);
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
			draw_set(mlx, mlx->openSet, (t_colour){0,100,0});
			draw_set(mlx, mlx->closedSet, (t_colour){100,0,0});
			draw_path(mlx, mlx->path, (t_colour){0,0,100});
		}
		else if (!compare_nodes(mlx->path, &END))
		{
			system("clear");
			ft_putendl("No path found");
		}
		mlx->step = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
	return (0);
}
