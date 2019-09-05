/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixels.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/08 16:05:12 by fhignett       #+#    #+#                */
/*   Updated: 2019/09/05 11:17:55 by flintlouis    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinding.h"

void		put_pixel(int x, int y, t_mlx *mlx, t_colour colour)
{
	int i;
	int	*mem;

	mem = (int*)mlx->data_addr;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = x + (y * mlx->size_line / 4);
		mem[i] = colour.b | (colour.g << 8) | (colour.r << 16);
	}
}

void			put_square(t_mlx *mlx, t_point grid, t_colour colour)
{
	int y;
	int x;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (y == 0 || x == 0)
				put_pixel(grid.x + x, grid.y + y, mlx, (t_colour){0,0,0});
			else
				put_pixel(grid.x + x, grid.y + y, mlx, colour);
			x++;
		}
		y++;
	}
}
