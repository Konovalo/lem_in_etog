/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zap_edge_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:21:18 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/22 15:26:10 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			zap_edge2(t_node **e_list, t_vertex **v1, t_vertex **v2, \
		t_vertex **v4)
{
	t_edge		*e1;
	t_edge		*e3;

	e1 = NULL;
	e3 = NULL;
	e1 = edge_create(*v1, *v4);
	e3 = edge_create(*v4, *v2);
	edge_list_add_all(e_list, e1);
	edge_list_add_all(e_list, e3);
	edge_list_add_first(&((*v4)->i_edges), e1);
	edge_list_add_first(&((*v4)->i_edges), e3);
	edge_list_add_first(&((*v1)->i_edges), e1);
	edge_list_add_first(&((*v2)->i_edges), e3);
}

int				zap_edge_ver2(t_vertex *ver, t_time *t, t_temp *temp, int kol)
{
	if (ver->name)
	{
		if (ft_strcmp(t->s1, ver->name) == 0)
		{
			if (ver->k == 0)
				temp->v1 = ver;
			else
				temp->v3 = ver;
			kol++;
		}
		else
		{
			if (ft_strcmp(t->s2, ver->name) == 0)
			{
				if (ver->k == 0)
					temp->v2 = ver;
				else
					temp->v4 = ver;
				kol++;
			}
		}
	}
	return (kol);
}

int				zap_edge_ver(t_node **v_list, t_time *t, t_temp *temp)
{
	int			kol;
	t_node		**new_n;

	kol = 0;
	new_n = v_list;
	while ((*new_n) && kol < 4)
	{
		kol = zap_edge_ver2(((t_vertex*)((*new_n)->data)), t, temp, kol);
		new_n = &((*new_n)->next);
	}
	return (kol);
}

void			zap_edge_678(t_node **e_list, t_temp *tmp)
{
	zap_edge6(e_list, &(tmp->v1), &(tmp->v4));
	zap_edge7(e_list, &(tmp->v2), &(tmp->v3));
	zap_edge8(e_list, &(tmp->v2), &(tmp->v4));
}

void			zap_edge513(t_node **e_list, t_vertex **v1, t_vertex **v4)
{
	t_edge		*e1;

	e1 = NULL;
	e1 = edge_create(*v1, *v4);
	edge_list_add_all(e_list, e1);
	edge_list_add_first(&((*v4)->i_edges), e1);
	edge_list_add_first(&((*v1)->i_edges), e1);
}

int				zap_edge(t_node **v_list, t_node **e_list, t_time *time)
{
	t_temp		tmp;

	ini_temp(&tmp);
	if (zap_edge_ver(v_list, time, &tmp) < 2)
		return (-1);
	if ((tmp.v1 && tmp.v2 && ft_strcmp(tmp.v1->name, tmp.v2->name) != 0) || \
			(tmp.v3 && tmp.v2 && ft_strcmp(tmp.v3->name, tmp.v2->name) != 0) \
			|| (tmp.v4 && tmp.v1 && ft_strcmp(tmp.v4->name, tmp.v1->name) != 0))
	{
		if (tmp.v1 && tmp.v2 && tmp.v1->type != START && tmp.v2->type != START \
				&& tmp.v4->type != END && tmp.v3->type != END)
			zap_edge_678(e_list, &tmp);
		if (tmp.v1 && tmp.v2 && tmp.v1->type == START && tmp.v2->type != END)
			zap_edge2(e_list, &tmp.v1, &tmp.v2, &tmp.v4);
		if (tmp.v2 && tmp.v1 && tmp.v2->type == START && tmp.v1->type != END)
			zap_edge3(e_list, &tmp.v1, &tmp.v2, &tmp.v3);
		if (tmp.v1 && tmp.v4 && tmp.v1->type != START && tmp.v4->type == END)
			zap_edge4(e_list, &tmp.v1, &tmp.v3, &tmp.v4);
		if (tmp.v2 && tmp.v3 && tmp.v2->type != START && tmp.v3->type == END)
			zap_edge5(e_list, &tmp.v2, &tmp.v3, &tmp.v4);
		if (tmp.v1 && tmp.v4 && tmp.v1->type == START && tmp.v4->type == END)
			zap_edge513(e_list, &tmp.v1, &tmp.v4);
	}
	return (1);
}
