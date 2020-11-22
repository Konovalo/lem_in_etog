/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zap_edge_ini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:32:08 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/22 15:32:41 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ini_temp(t_temp *temp)
{
	temp->v1 = (t_vertex*)NULL;
	temp->v2 = (t_vertex*)NULL;
	temp->v3 = (t_vertex*)NULL;
	temp->v4 = (t_vertex*)NULL;
}

void		zap_edge3(t_node **e_list, t_vertex **v1, t_vertex **v2, \
		t_vertex **v3)
{
	t_edge	*e1;
	t_edge	*e3;

	e1 = NULL;
	e3 = NULL;
	e1 = edge_create((*v3), (*v1));
	e3 = edge_create((*v2), (*v3));
	edge_list_add_all(e_list, e1);
	edge_list_add_all(e_list, e3);
	edge_list_add_first(&((*v2)->i_edges), e3);
	edge_list_add_first(&((*v3)->i_edges), e3);
	edge_list_add_first(&((*v3)->i_edges), e1);
	edge_list_add_first(&((*v1)->i_edges), e1);
}
