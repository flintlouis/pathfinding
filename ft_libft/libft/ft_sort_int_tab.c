/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_int_tab.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 17:37:35 by fhignett      #+#    #+#                 */
/*   Updated: 2019/01/18 17:37:36 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;

	if (!tab)
		return ;
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tab[i] ^= tab[i + 1];
			tab[i + 1] ^= tab[i];
			tab[i] ^= tab[i + 1];
			i = 0;
		}
		else
			i++;
	}
}
