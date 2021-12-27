/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:40:46 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/24 22:56:43 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_set *set_a)
{
	int	i;
	int	temp;

	if (set_a->count < 2)
		return ;
	i = 0;
	temp = set_a->mess[0];
	while (i < set_a->count - 1)
	{
		set_a->mess[i] = set_a->mess[i + 1];
		++i;
	}
	set_a->mess[set_a->count - 1] = temp;
	set_a->left = set_a->mess[0];
	write(1, "ra\n", 3);
}

void	rb(t_set *set_b)
{
	int	i;
	int	temp;
	int	temp1;

	i = 0;
	temp = set_b->mess[0];
	temp1 = set_b->sort[0];
	while (i < set_b->count - 1)
	{
		set_b->mess[i] = set_b->mess[i + 1];
		set_b->sort[i] = set_b->sort[i + 1];
		i++;
	}
	set_b->mess[set_b->count - 1] = temp;
	set_b->sort[set_b->count - 1] = temp1;
	write(1, "rb\n", 3);
}

void	rra(t_set *set_a)
{
	int	i;
	int	temp;

	if (set_a->count < 2)
		return ;
	i = set_a->count;
	temp = set_a->mess[set_a->count - 1];
	while (i != 0)
	{
		set_a->mess[i] = set_a->mess[i - 1];
		--i;
	}
	set_a->mess[0] = temp;
	set_a->left = set_a->mess[0];
	write(1, "rra\n", 4);
}

void	rrb(t_set *set_b)
{
	int	i;
	int	temp;
	int	temp1;

	i = set_b->count;
	temp = set_b->mess[set_b->count - 1];
	temp1 = set_b->sort[set_b->count - 1];
	while (i > 0)
	{
		set_b->mess[i] = set_b->mess[i - 1];
		set_b->sort[i] = set_b->sort[i - 1];
		--i;
	}
	set_b->mess[0] = temp;
	set_b->sort[0] = temp1;
	write(1, "rrb\n", 4);
}
