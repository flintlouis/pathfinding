/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit_list.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:22:42 by fhignett      #+#    #+#                 */
/*   Updated: 2019/01/14 16:22:43 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		countc(char *s, char c)
{
	int	x;
	int i;

	x = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		x++;
	}
	return (x);
}

static char		*filltemp(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static	void	makenode(t_list **head, char *s, char c)
{
	char	*temp;
	int		chrs;

	chrs = countc(s, c);
	if (!(temp = (char*)malloc(sizeof(char) * chrs + 1)))
		return ;
	filltemp(temp, s, chrs);
	ft_lstadd_back(head, ft_lstnew(temp, chrs + 1));
	free(temp);
}

t_list			*ft_strsplit_list(const char *s, char c)
{
	t_list	*head;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	head = NULL;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			makenode(&head, (char*)&s[i], c);
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (head);
}
