/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:39:49 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/22 18:46:17 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			zap_print_ant(t_node **mass, int *ogi, t_ant_node *anti,\
			t_read *read)
{
	t_node	*ti;
	t_node	*tim;
	int		o;
	int		i;

	i = 0;
	ti = read->paths;
	while (anti && ti)
	{
		tim = ((t_node*)ti->data)->next;
		o = 0;
		if (anti->ant == 0 && i < read->ant)
			ogi[i++] = -1;
		while (anti->ant > 0 && tim)
		{
			mass[i] = tim;
			ogi[i] = o;
			o++;
			anti->ant--;
			i++;
		}
		ti = ti->next;
		anti = anti->next;
	}
	return (0);
}

int			print_ant2(t_read *read, int *ogi, t_node **mass)
{
	int		i;
	int		k;

	i = 0;
	k = 1;
	while (i < read->ant)
	{
		if (ogi[i] == 0 && mass[i])
		{
			k = 0;
			ft_printf("L%d-%s ", i + 1, \
					((t_vertex*)((t_node*)mass[i]->data))->name);
			mass[i] = (t_node*)mass[i]->next;
		}
		else
			ogi[i]--;
		i++;
	}
	if (k == 0)
		ft_printf("\n");
	return (k);
}

void		print_ant(t_read *read, t_node *paths, t_ant_node *an)
{
	t_node	**mass;
	int		*ogi;
	int		i;
	int		k;

	read->paths = paths;
	mass = (t_node**)malloc(sizeof(t_node*) * read->ant);
	ogi = (int*)malloc(sizeof(int) * read->ant);
	k = zap_print_ant(mass, ogi, an, read);
	while (k == 0)
	{
		k = print_ant2(read, ogi, mass);
	}
	fr_mass(mass, ogi, read->ant);
}
