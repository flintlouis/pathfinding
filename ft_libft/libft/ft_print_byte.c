/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_byte.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 16:58:57 by fhignett      #+#    #+#                 */
/*   Updated: 2019/01/18 16:59:03 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_byte(unsigned char byte)
{
	int idx;

	idx = 7;
	while (idx >= 0)
	{
		if ((byte & (1 << idx)) != 0)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		idx--;
	}
}
