/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mids_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:40:31 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/24 23:48:06 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Moves all numbers lower than current mid value from a to b
*/

void	move_portions_to_b(t_set *set_a, t_set *set_b)
{
	int	pbs;

	++set_a->mid_num;
	if (set_a->count > 250)
		pbs = set_a->count / 5;
	else if (set_a->count > 175)
		pbs = set_a->count / 4;
	else if (set_a->count > 5)
		pbs = set_a->count / 3;
	else
		pbs = set_a->count / 2;
	while (set_a->left < set_a->mid)
	{
		pb(set_a, set_b);
		--pbs;
	}
	move_to_b_util(set_a, set_b, pbs);
}

void	move_to_b_util(t_set *set_a, t_set *set_b, int pbs)
{
	while (pbs != 0)
	{
		if (set_a->left >= set_a->mid)
		{
			if (pbs <= 2)
			{
				last_push_to_b(set_a, set_b);
				pbs--;
			}
			else
				ra(set_a);
		}
		else
		{
			pb(set_a, set_b);
			--pbs;
		}
	}
	update_set_A(set_a);
}

/*
	Make sure that after move_a_to_b function is called
	I have correct values in my structure
*/

void	update_set_A(t_set *set_a)
{
	int	i;
	int	j;

	i = find_min(set_a);
	j = 0;
	while (j < set_a->count)
		set_a->sort[j++] = i++;
	if (set_a->count > 250)
		set_a->mid = set_a->sort[set_a->count / 5];
	else if (set_a->count > 175)
		set_a->mid = set_a->sort[set_a->count / 4];
	else if (set_a->count > 5)
		set_a->mid = set_a->sort[set_a->count / 3];
	else
		set_a->mid = set_a->sort[set_a->count / 2];
}

/*
	Function which is needed to minimize amount of operations needed for last push
*/

void	last_push_to_b(t_set *set_a, t_set *set_b)
{
	int	ras;
	int	rras;
	int	i;

	i = 0;
	ras = 0;
	rras = 1;
	while (set_a->mess[i++] >= set_a->mid)
		++ras;
	i = set_a->count - 1;
	while (set_a->mess[i] >= set_a->mid)
	{
		--i;
		++rras;
	}
	last_push_util(set_a, set_b, ras, rras);
}

void	last_push_util(t_set *set_a, t_set *set_b, int ras, int rras)
{
	if (ras < rras)
	{
		while (ras != 0)
		{
			ra(set_a);
			--ras;
		}
	}
	else
	{
		while (rras != 0)
		{
			rra(set_a);
			--rras;
		}
	}
	pb(set_a, set_b);
}
