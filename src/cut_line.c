/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 00:13:07 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/21 22:51:09 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				cut_line5(char *l, t_read **read)
{
	(*read)->i = 0;
	while ((*read)->i < (*read)->len && l[(*read)->i] != '-')
		(*read)->i++;
	return ((*read)->i);
}

int				cut_line4(char *l, t_read **read)
{
	(*read)->i = 0;
	while ((*read)->i < (*read)->len && l[(*read)->i] != ' ')
		(*read)->i++;
	return ((*read)->i);
}

int				cut_line7(char *l, t_read *read, t_node **v_l, t_node **e_list)
{
	if ((!(read->time.s1 = ft_strdup(l))) || \
		(!(read->time.s2 = ft_strdup(&l[read->i]))) || \
		zap_edge(v_l, e_list, &(read->time)) < 0)
		return (-1);
	return (0);
}

int				cut_line2(char *l, t_read *read, t_node **v_l, t_node **e_list)
{
	read->len = ft_strlen(l);
	read->i = cut_line4(l, &read);
	if (read->i < read->len)
		l[read->i] = '\0';
	if (!(read->time.s1 = ft_strdup(l)))
		return (-1);
	if (read->i == read->len)
	{
		ft_strdel(&(read->time.s1));
		if (read->tim == 0)
		{
			read->tim = 1;
			ver_list_add(v_l, read->v);
		}
		read->i = cut_line5(l, &read);
		l[read->i] = '\0';
		read->i++;
		if (read->i > read->len || cut_line7(l, read, v_l, e_list) < 0)
			return (-1);
		ft_strdel(&(read->time.s1));
		ft_strdel(&(read->time.s2));
	}
	else
		return (cut_line3(l, read, v_l));
	return (1);
}

int					cut_line(char *line, t_read *read, t_node **v, t_node **e)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	if (line[0] != '#' && read->ant == -1 && (read->ant = ft_atoi(line)) > 0 \
			&& ft_strlen(line) == ft_sizenbr(read->ant))
	{
		if (read->ant < 0)
			return (-1);
		else
			return (1);
	}
	if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strcmp(line, "##start") == 0)
			read->n += 1;
		else
		{
			if (ft_strcmp(line, "##end") == 0)
				read->k += 1;
		}
		return (1);
	}
	ft_printf("****\n");
	if (cut_line2(line, read, v, e) < 0)
		return (-1);
	else
		return (-1);
	
	return (1);
}
