/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:21:12 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/06 21:31:13 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_set *set_a, t_set *set_b, t_set *set_0)
{
	free (set_0->mess);
	set_0->mess = NULL;
	free (set_0->sort);
	set_0->sort = NULL;
	free (set_a->mess);
	set_a->mess = NULL;
	free (set_a->sort);
	set_a->sort = NULL;
	free (set_b->mess);
	set_b->mess = NULL;
	free (set_b->sort);
	set_b->sort = NULL;
}
