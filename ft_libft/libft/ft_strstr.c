/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:53:17 by fhignett      #+#    #+#                 */
/*   Updated: 2019/01/11 17:53:18 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int x;

	i = 0;
	x = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		while (haystack[i] != '\0' && haystack[i] == needle[x])
		{
			i++;
			x++;
			if (needle[x] == '\0')
				return ((char*)&haystack[i - x]);
		}
		i = i - x;
		x = 0;
		i++;
	}
	return (NULL);
}
