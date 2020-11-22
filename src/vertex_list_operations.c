/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_list_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 00:21:58 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/22 00:32:32 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_vertex		*vertex_list_get_first(t_node **list)
{
	return (t_vertex *)dll_get_first(list);
}

t_node			*vertex_list_push(t_node **stack, t_vertex *v)
{
	if (!*stack)
	{
		*stack = dll_new_node(v);
		return (*stack);
	}
	return (dll_push(stack, v));
}

t_vertex		*vertex_list_pop(t_node **stack)
{
	return (t_vertex *)dll_pop(stack);
}

t_node			*ver_list_add(t_node **list, t_vertex *v)
{
	return (dll_add_first(list, v));
}

t_ant_node		*dll_new_node_an(int k)
{
	t_ant_node	*node;

	if (!(node = (t_ant_node *)malloc(sizeof(t_ant_node))))
		return (NULL);
	node->next = NULL;
	node->ant = k;
	return (node);
}
