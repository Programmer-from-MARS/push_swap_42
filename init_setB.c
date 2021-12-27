/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setB.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:40:23 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/24 23:34:15 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Inittialize set_B, allocate space for 2 sets
*/

void	init_setB(t_set *set_a, t_set *set_b)
{
	int	*set;
	int	*flags;
	int	i;

	set = (int *)malloc(sizeof(int) * set_a->count);
	if (!set)
		error_occured("Error\n");
	flags = (int *)malloc(sizeof(int) * set_a->count);
	if (!flags)
		error_occured("Error\n");
	set_b->sort = flags;
	set_b->mess = set;
	i = 0;
	while (i < set_a->count)
	{
		set[i] = 0;
		flags[i++] = 0;
	}
}
