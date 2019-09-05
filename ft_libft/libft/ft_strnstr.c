/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:53:39 by fhignett      #+#    #+#                 */
/*   Updated: 2019/01/11 17:53:40 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		x;

	i = 0;
	x = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i] != '\0' && haystack[i] == needle[x] && i < len)
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
