/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/22 15:15:02 by fhignett       #+#    #+#                */
/*   Updated: 2019/03/14 16:58:44 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int			restzero(t_list **temp, char **line)
{
	if ((*temp)->content == NULL || ft_strcmp((*temp)->content, "\0") == 0)
	{
		*line = NULL;
		(*temp)->content_size = -1;
		return (0);
	}
	*line = ft_strdup((*temp)->content);
	if (*line == NULL)
		return (-1);
	free((*temp)->content);
	(*temp)->content = NULL;
	return (1);
}

static int			saveline(t_list **temp, char **line, char *rest)
{
	char *s;

	if (rest == NULL)
		return (restzero(temp, line));
	*rest = '\0';
	s = ft_strdup(rest + 1);
	if (s == NULL)
		return (-1);
	*line = ft_strdup((*temp)->content);
	if (*line == NULL)
		return (-1);
	free((*temp)->content);
	(*temp)->content = s;
	return (1);
}

static t_list		*fdcheck(t_list **list, const int fd)
{
	t_list *new;

	new = *list;
	while (new)
	{
		if (new->content_size == (size_t)fd)
			return (new);
		new = new->next;
	}
	new = ft_lstnew("", 1);
	if (new == NULL)
		return (NULL);
	new->content_size = fd;
	ft_lstadd(list, new);
	return (new);
}

static int			ft_errors(char **buff, const int fd, t_list **temp)
{
	static t_list	*list;

	*buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (buff == NULL || fd < 0)
		return (-1);
	*temp = fdcheck(&list, fd);
	if (temp == NULL)
		return (-1);
	return (1);
}

int					ft_get_next_line(const int fd, char **line)
{
	t_list			*temp;
	char			*rest;
	char			*buff;
	ssize_t			ret;

	ret = ft_errors(&buff, fd, &temp);
	if (ret == -1)
		return (-1);
	while (ret > 0)
	{
		rest = ft_strchr(temp->content, '\n');
		if (rest != NULL)
			break ;
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == 0)
			break ;
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		rest = temp->content;
		temp->content = ft_strjoin(temp->content, buff);
		free(rest);
	}
	free(buff);
	return (saveline(&temp, line, rest));
}
