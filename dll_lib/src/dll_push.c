/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:15:39 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 15:19:08 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

t_node	*dll_push(t_node **list, void *data)
{
	return (dll_add_first(list, data));
}
