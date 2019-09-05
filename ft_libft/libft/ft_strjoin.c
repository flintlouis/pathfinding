/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 14:52:18 by fhignett      #+#    #+#                 */
/*   Updated: 2019/01/14 14:52:18 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;
	int		x;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	x = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (s1[x] != '\0')
		str = ft_strcpy(str, s1);
	i = ft_strlen(s1);
	x = 0;
	while (s2[x] != '\0')
	{
		str[i] = s2[x];
		i++;
		x++;
	}
	str[i] = '\0';
	return (str);
}
