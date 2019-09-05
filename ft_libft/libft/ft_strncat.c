/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:41:24 by fhignett      #+#    #+#                 */
/*   Updated: 2019/01/10 11:41:25 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	x;

	x = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[x] != '\0' && x < n)
	{
		s1[i] = s2[x];
		x++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
