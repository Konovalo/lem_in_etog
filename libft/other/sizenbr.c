/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizenbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:44:34 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 18:53:17 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizenbr(int nbr)
{
	int	n;

	n = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		n++;
	nbr = nbr / 10;
	n++;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		nbr /= 10;
		n++;
	}
	return (n);
}

int	ft_lsizenbr(long int nbr)
{
	int	n;

	n = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		n++;
	nbr = nbr / 10;
	n++;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		nbr /= 10;
		n++;
	}
	return (n);
}
