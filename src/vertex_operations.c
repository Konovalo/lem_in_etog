/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 00:35:00 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/22 19:29:38 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			vertex_cmp_forked(t_vertex *v1, t_vertex *v2)
{
	if (v1 && v2 && !ft_strcmp(v1->name, v2->name) && v1->k != v2->k)
		return (TRUE);
	return (FALSE);
}

int			vertex_cmp2(t_vertex *v1, t_vertex *v2)
{
	if (v1 == v2)
		return (TRUE);
	if (v1 && v2 && !ft_strcmp(v1->name, v2->name))
		return (TRUE);
	return (FALSE);
}

int			vertex_cmp(t_vertex *v1, t_vertex *v2)
{
	if (v1 == v2)
		return (TRUE);
	if (v1 && v2 && !ft_strcmp(v1->name, v2->name) && v1->k == v2->k)
		return (TRUE);
	return (FALSE);
}

t_vertex	*vertex_create(t_int t, char *name, t_vertex_type type, int k)
{
	t_vertex	*v;

	v = (t_vertex *)malloc(sizeof(t_vertex));
	v->x = t.x;
	v->y = t.y;
	v->name = name;
	v->type = type;
	v->bfs_level = 0;
	v->i_edges = NULL;
	v->k = k;
	v->visited = 0;
	return (v);
}
