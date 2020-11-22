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

#include "dll.h"

/*
** Возвращает данные узла на который указывает передаваемый указатель.
** Узел удаляется.
** После удаления узла указатель перемещается:
** 1) При удалаении первого узла, на следующий узел.
** 2) При удалении последнего узла, на предудыщий узел.
** 3) При удалении узла из середины списка, на следующий за удаляемым узел.
**
** @param Ссылка на извлекаемый узел списка
** @return Ссылка на данные узла списка
*/

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
