/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:40:49 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/24 22:59:38 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_set *set_a)
{
	int	temp;

	if (set_a->count < 2)
		return ;
	temp = set_a->mess[0];
	set_a->mess[0] = set_a->mess[1];
	set_a->mess[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_set *set_b)
{
	int	temp;

	if (set_b->count < 2)
		return ;
	temp = set_b->mess[0];
	set_b->mess[0] = set_b->mess[1];
	set_b->mess[1] = temp;
}

void	pa(t_set *set_a, t_set *set_b)
{
	int	i;

	if (set_b->count == 0)
		return ;
	i = set_a->count;
	while (i >= 0)
	{
		set_a->mess[i + 1] = set_a->mess[i];
		i--;
	}
	set_a->mess[0] = set_b->mess[0];
	set_a->left = set_a->mess[0];
	set_b->count--;
	set_a->count++;
	i = 0;
	while (i < set_b->count)
	{
		set_b->mess[i] = set_b->mess[i + 1];
		set_b->sort[i] = set_b->sort[i + 1];
		i++;
	}
	set_b->mess[i] = 0;
	set_b->sort[i] = 0;
	set_b->left = set_b->mess[0];
	write(1, "pa\n", 3);
}

void	pb(t_set *set_a, t_set *set_b)
{
	int	i;

	if (set_a->count == 0)
		return ;
	i = set_b->count;
	while (i >= 0)
	{
		set_b->mess[i + 1] = set_b->mess[i];
		set_b->sort[i + 1] = set_b->sort[i];
		i--;
	}
	set_b->mess[0] = set_a->mess[0];
	set_b->sort[0] = set_a->mid_num;
	set_b->left = set_b->mess[0];
	set_a->count--;
	set_b->count++;
	i = 0;
	while (i < set_a->count)
	{
		set_a->mess[i] = set_a->mess[i + 1];
		i++;
	}
	set_a->mess[i] = 0;
	set_a->left = set_a->mess[0];
	write(1, "pb\n", 3);
}
