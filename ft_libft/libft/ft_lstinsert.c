/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstinsert.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 16:47:22 by fhignett      #+#    #+#                 */
/*   Updated: 2019/01/21 16:48:35 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list *node, t_list *new)
{
	if (!node || !new)
		return ;
	new->next = node->next;
	node->next = new;
}
