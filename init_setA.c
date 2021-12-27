/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setA.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:40:20 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/24 23:31:59 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Inittialize set_A, set dependency for mid value depending on set_A count
*/

void	init_setA(t_set *set_a, t_set *set_0)
{
	set_a->mess = easy_set(set_0);
	set_a->sort = easy_sort(set_0->count);
	set_a->count = set_0->count;
	if (set_a->count > 250)
		set_a->mid = set_a->sort[set_a->count / 5];
	else if (set_a->count > 175)
		set_a->mid = set_a->sort[set_a->count / 4];
	else if (set_a->count > 5)
		set_a->mid = set_a->sort[set_a->count / 3];
	else
		set_a->mid = set_a->sort[set_a->count / 2];
	set_a->left = set_a->mess[0];
}

/*
	Transform set_0 to set_A from 0 to n, 
	but make sure that original order is unchanges
*/

int	*easy_set(t_set *set_0)
{
	int	*nums;
	int	i;
	int	j;

	i = 0;
	nums = (int *)malloc(sizeof(int) * set_0->count);
	if (!nums)
		error_occured("Error\n");
	while (i < set_0->count)
	{
		j = 0;
		while (j < set_0->count)
		{
			if (set_0->mess[i] == set_0->sort[j])
				nums[i] = j + 1;
			j++;
		}
		i++;
	}
	return (nums);
}

/*
	Create set_A sort in sorted order min to max
*/

int	*easy_sort(int n)
{
	int	*nums;
	int	i;

	nums = (int *)malloc(sizeof(int) * n);
	if (!nums)
		error_occured("Error\n");
	i = 0;
	while (i < n)
	{
		nums[i] = i + 1;
		i++;
	}
	return (nums);
}

/*
	Make sure that set we are working with is not sorted yet
*/

int	check_A_for_sorted(t_set *set_a)
{
	int	i;
	int	j;

	i = set_a->count;
	if (i == 2 && set_a->mess[0] != set_a->sort[0])
	{
		ra(set_a);
		return (0);
	}
	j = 0;
	while (i != 0)
	{
		if (set_a->mess[j] != set_a->sort[j])
			return (1);
		i--;
		j++;
	}
	return (0);
}
