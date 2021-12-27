/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_set0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:40:17 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/24 23:22:30 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Initiialise sets with zero / NULL values
*/

void	create_sets(t_set *set_a, t_set *set_b, t_set *set_0)
{
	set_a->sort = NULL;
	set_a->mess = NULL;
	set_a->count = 0;
	set_a->mid = 0;
	set_a->mid_num = 0;
	set_a->left = 0;
	set_b->sort = NULL;
	set_b->mess = NULL;
	set_b->count = 0;
	set_b->mid = 0;
	set_b->mid_num = 0;
	set_b->left = 0;
	set_0->sort = NULL;
	set_0->mess = NULL;
	set_0->count = 0;
	set_0->mid = 0;
	set_0->mid_num = 0;
	set_0->left = 0;
}

/*
	Initialize set_0
*/

void	init_set0(t_set *set_0, int *set, int argc)
{
	set_0->mess = set;
	set_0->sort = sort_set(set, argc);
	set_0->count = argc - 1;
	set_0->mid = set_0->sort[set_0->count / 2];
	set_0->left = set[0];
}

/*
	Sort sets using buble sort, I will need it later to for set A,
	where I keep all values from 1 to n.
*/

int	*sort_set(int *set, int argc)
{
	int		i;
	int		*set_sorted;

	set_sorted = (int *)malloc(sizeof(int) * (argc - 1));
	if (!set_sorted)
		error_occured("Error\n");
	i = -1;
	while (i++ < argc - 1)
		set_sorted[i] = set[i];
	sort_set_util(set_sorted, argc);
	return (set_sorted);
}

void	sort_set_util(int *set_sorted, int argc)
{
	int	temp;
	int	i;
	int	j;

	i = -1;
	while (++i < (argc - 2))
	{
		j = -1;
		while (++j < (argc - i - 2))
		{
			if (set_sorted[j] > set_sorted[j + 1])
			{
				temp = set_sorted[j];
				set_sorted[j] = set_sorted[j + 1];
				set_sorted[j + 1] = temp;
			}
		}
	}
}

/*
	Allocate memory for int array and check values using atoi for push_swap
*/

int	*check_initial_set(int argc, char **argv)
{
	int	i;
	int	*initial_set;

	i = 0;
	initial_set = (int *)malloc(sizeof(int) * argc);
	if (!initial_set)
		error_occured("Error\n");
	while (i < argc - 1)
	{
		initial_set[i] = atoi_p_s(argv[1 + i]);
		++i;
	}
	return (initial_set);
}
