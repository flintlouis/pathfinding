/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:22:29 by fhignett      #+#    #+#                 */
/*   Updated: 2019/01/14 16:22:31 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		start(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
		if (s[i] == '\0')
		{
			i = 0;
			break ;
		}
	}
	return (i);
}

static int		end(char const *s)
{
	int size;

	size = ft_strlen(s) - 1;
	while (s[size] == ' ' || s[size] == '\t' || s[size] == '\n')
		size--;
	return (size);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		x;
	int		size;

	if (!s)
		return (NULL);
	i = start(s);
	size = end(s) - i + 1;
	str = (char*)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	x = 0;
	while (x < size)
	{
		str[x] = s[i];
		x++;
		i++;
	}
	str[x] = '\0';
	return (str);
}
