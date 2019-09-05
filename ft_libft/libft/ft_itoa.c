/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:22:55 by fhignett       #+#    #+#                */
/*   Updated: 2019/04/18 11:58:20 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_len(int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len += 1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char		*ft_iszero(void)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		x;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	x = n;
	len = ft_len(n);
	n = ABS(n);
	if (n == 0)
		return (ft_iszero());
	s = (char*)malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	len -= 1;
	while (len >= 0)
	{
		s[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	if (x < 0)
		s[0] = '-';
	return (s);
}
