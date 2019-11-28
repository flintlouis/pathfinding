#ifndef PATHFINDING_H
# define PATHFINDING_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define KEY_ESC		53
# define KEY_SPACE		49
# define L_MOUSE		1
# define KEY_R			15
# define KEY_P			35
# define S				mlx->saved->s
# define E				mlx->saved->e

# define OBSTACLES		5.5
# define GRID_COL		100 /* Check that START/END still are possible */
# define GRID_ROWS		100 /* Check that START/END still are possible */
# define WIDTH			1000
# define HEIGHT			800
# define MEM(x)			(x*)ft_memalloc(sizeof(x))
# define START			(t_point){23,16}
# define END			(t_point){91,82}

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
	double				f; // f(n) = g(n) + h(n)
	double				g; // steps taken from start
	double				h; // estimated distance to end
	char				obstacle:1;
	t_point				loc;
	struct s_node		**neighbors;
	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

typedef	struct			s_saved
{
	int					**grid;
	int					width;
	int					height;
	t_point				s;
	t_point				e;
}						t_saved;

typedef	struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*image;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	char				*file;
	char				*cmd;
	char				step:1;
	char				pause:1;
	char				no_path:1;
	t_saved				*saved;
	t_node				**grid;
	t_node				*openSet;
	t_node				*closedSet;
	t_node				*path;
}						t_mlx;

int 					w;
int 					h;
t_node					*start;
t_node					*end;

int						pathfinding(t_mlx *mlx);
int						close_window(void *ptr);
int						release_key(int key, t_mlx *mlx);
int						press_key(int key, t_mlx *mlx);
int						mouse_press(int button, int x, int y, t_mlx *mlx);
int						compare_nodes(t_node *s1, t_node *s2);
int 					in_set(t_node **set, t_node *node);

double					heuristic(t_node *a, t_node *b);

long					time_between_frames(void);

void					reset_game(t_mlx *mlx);
void					put_square(t_mlx *mlx, t_point grid, t_colour colour);
void					setup_pathfinding(int argc, char **argv);
void					draw_start_end(t_mlx *mlx, t_colour c);
void					draw_grid(t_mlx *mlx, t_colour c);
void					draw_path(t_mlx *mlx, t_node *path, t_colour c);
void					draw_set(t_mlx *mlx, t_node *set, t_colour c);
void					add_node(t_node **set, t_node *node);
void					rm_node(t_node **set, t_node *node);
void					save_grid(t_mlx *mlx);
void					load_grid(t_mlx *mlx);
void					generate_grid(t_mlx *mlx);
void					load_grid_info(t_mlx *mlx);

#endif
