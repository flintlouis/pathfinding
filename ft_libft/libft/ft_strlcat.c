/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:41:36 by fhignett      #+#    #+#                 */
/*   Updated: 2019/01/10 11:41:37 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		x;
	size_t	dstlen;
	int		srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	x = dstlen;
	if (size <= dstlen)
		return (size + srclen);
	while ((size - x) > 1 && src[i])
	{
		dst[x] = src[i];
		x++;
		i++;
	}
	dst[x] = '\0';
	return (srclen + dstlen);
}
