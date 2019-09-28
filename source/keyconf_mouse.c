#include "pathfinding.h"

static void get_node_info(t_mlx *mlx, int x, int y)
{
	int i;
	int j;
	t_node *node;

	i = x / w;
	j = y / h;
	system("clear");
	node = &mlx->grid[i][j];
	printf("Loc  : (%d, %d)\nF    : %.2f\nG    : %.2f\nH    : %.2f\n",
	node->loc.x, node->loc.y, node->f, node->g, node->h);
	if (node->prev)
		printf("Prev : (%d, %d)\n", node->prev->loc.x, node->prev->loc.y);
	else
		ft_putendl("Prev : (NULL)");
	for (int n = 0; n < 8; n++) {
		if (!node->neighbors[n])
			ft_putendl("NULL");
		else {
			switch (n) {
				case 0: ft_putstr("Recths");
					break ;
				case 1: ft_putstr("Links");
					break ;
				case 2: ft_putstr("Onder");
					break ;
				case 3: ft_putstr("Boven");
					break ;
				case 4: ft_putstr("Rechts boven");
					break ;
				case 5: ft_putstr("Links onder");
					break ;
				case 6: ft_putstr("Rechts onder");
					break ;
				default: ft_putstr("Links boven");
			}
			t_point loc = node->neighbors[n]->loc;
			printf(" (%d, %d)\n", loc.x, loc.y);
		}
	}
}

int				mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (button == L_MOUSE)
		get_node_info(mlx, x, y);
	return (0);
}
