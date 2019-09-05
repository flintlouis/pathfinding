/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:22:42 by fhignett      #+#    #+#                 */
/*   Updated: 2019/01/14 16:22:43 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		countc(char const *s, int i, char c)
{
	int	x;

	x = 0;
	while (s[i] != c && s[i] != '\0')
	{
		x++;
		i++;
	}
	return (x);
}

static char		**malloc_array(char const *s, char **arraystr, char c)
{
	int		i;
	int		x;
	int		y;
	int		chrs;

	i = 0;
	x = 0;
	y = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			chrs = countc(s, i, c);
			if (!(arraystr[x] = (char*)malloc(sizeof(char) * chrs + 1)))
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				arraystr[x][y++] = s[i++];
			arraystr[x++][y] = '\0';
			y = 0;
		}
		else
			i++;
	}
	arraystr[x] = NULL;
	return (arraystr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arraystr;
	int		words;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	if (!(arraystr = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	arraystr = malloc_array(s, arraystr, c);
	return (arraystr);
}
