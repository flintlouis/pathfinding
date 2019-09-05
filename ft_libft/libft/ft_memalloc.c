/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 10:53:24 by fhignett      #+#    #+#                 */
/*   Updated: 2019/01/14 10:53:25 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*array;

	array = (void*)malloc(size);
	if (!array)
		return (NULL);
	while (size > 0)
	{
		size--;
		array[size] = 0;
	}
	return (array);
}
