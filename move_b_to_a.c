/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:40:29 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/24 23:45:18 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Each time this function called moves all values lower than set_A->mid to set_B
*/

void	move_b_to_a(t_set *set_a, t_set *set_b)
{
	int	max;

	max = find_max(set_b);
	while (set_b->count > 1)
	{
		move_pair_b_to_a(set_a, &(*set_b), max);
		if (set_a->mess[0] > set_a->mess[1])
			sa(set_a);
		max = find_max(set_b);
	}
	pa(set_a, set_b);
	if (set_a->mess[0] > set_a->mess[1])
		sa(set_a);
}

/*
	Searches for two highest numbers in set_B and countes how many rotations
	are needed to move each, then if second highes number is moved uses sa function,
	so set_a set is always sorted.
*/

void	move_pair_b_to_a(t_set *set_a, t_set *set_b, int max)
{
	int	i;
	int	rbs;
	int	rrbs;

	i = 0;
	rrbs = 1;
	rbs = 0;
	while (set_b->mess[i] != max && set_b->mess[i] != max - 1)
	{
		++i;
		++rbs;
	}
	i = set_b->count - 1;
	while (set_b->mess[i] != max && set_b->mess[i] != max - 1)
	{
		--i;
		++rrbs;
	}
	move_b_to_a_util(set_a, set_b, rbs, rrbs);
}

void	move_b_to_a_util(t_set *set_a, t_set *set_b, int rbs, int rrbs)
{
	if (rbs < rrbs)
	{
		while (rbs != 0)
		{
			rb(set_b);
			--rbs;
		}
	}
	else
	{
		while (rrbs != 0)
		{
			rrb(set_b);
			--rrbs;
		}
	}
	pa(set_a, set_b);
}

int	find_max(t_set *set_b)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (i < set_b->count)
	{
		if (set_b->mess[i] > max)
			max = set_b->mess[i];
		i++;
	}
	return (max);
}

int	find_min(t_set *set_b)
{
	int	min;
	int	i;

	min = set_b->mess[0];
	i = 0;
	while (i < set_b->count)
	{
		if (set_b->mess[i] < min && min != 0)
			min = set_b->mess[i];
		i++;
	}
	return (min);
}
