#ifndef PATHFINDING_H
# define PATHFINDING_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define KEY_ESC		53

# define GRID_COL		25
# define GRID_ROWS		25
# define HEIGHT			800
# define WIDTH			800
# define MEM(x)			(x*)ft_memalloc(sizeof(x))
# define START			mlx->grid[0][0]
# define END			mlx->grid[10][20]

int w;
int h;

typedef unsigned char	t_byte;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_colour
{
	t_byte				r;
	t_byte				g;
	t_byte				b;
}						t_colour;


typedef struct			s_node
{
	int					f; // f(n) = g(n) + h(n)
	int					g; // steps taken from start
	int					h; // estimated distance to end
	t_point				loc;
	struct s_node		**neighbors;
	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

typedef	struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*image;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	t_node				**grid;
	t_node				*openSet;
	t_node				*closedSet;
	t_node				*path;
}						t_mlx;

int						pathfinding(t_mlx *mlx);
int						close_window(void *ptr);
int						release_key(int key, t_mlx *mlx);
int						press_key(int key, t_mlx *mlx);
int						mouse_move(int x, int y, t_mlx *mlx);
int						mouse_press(int button, int x, int y, t_mlx *mlx);
int						mouse_release(int button, int x, int y, t_mlx *mlx);
int						compare_nodes(t_node *s1, t_node *s2);
int 					in_set(t_node **set, t_node *node);

long					time_between_frames(void);

void					put_square(t_mlx *mlx, t_point grid, t_colour colour);
void					setup_pathfinding(void);
void					draw_grid(t_mlx *mlx, t_colour c);
void					draw_path(t_mlx *mlx, t_node *path, t_colour c);
void					draw_set(t_mlx *mlx, t_node *set, t_colour c);
void					add_node(t_node **set, t_node *node);
void					rm_node(t_node **set, t_node *node);

#endif