/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyconf_keys.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 14:18:18 by nvreeke        #+#    #+#                */
/*   Updated: 2019/09/04 12:41:31 by flintlouis    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinding.h"

int			close_window(void *ptr)
{
	(void)ptr;
	exit(0);
	return (0);
}

int			release_key(int key, t_mlx *mlx)
{
	return (0);
}

int			press_key(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		close_window(0);
	return (0);
}
