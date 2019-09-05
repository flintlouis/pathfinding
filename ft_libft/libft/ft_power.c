/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_power.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 17:31:04 by fhignett      #+#    #+#                 */
/*   Updated: 2019/02/04 17:31:43 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_power(int x, size_t n)
{
	int res;

	res = 1;
	while (n)
	{
		n--;
		res *= x;
	}
	return (res);
}
