/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:13:05 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 15:18:23 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		*dll_get(t_node **list)
{
	void	*data;
	t_node	*to_delete;

	if (!list || !*list)
		return (NULL);
	if (!(*list)->prev)
		return (dll_get_first(list));
	if (!(*list)->next)
		return (dll_get_last(list));
	data = (void *)(*list)->data;
	to_delete = *list;
	*list = (*list)->next;
	(*list)->prev = (*list)->prev->prev;
	free(to_delete);
	return (data);
}
