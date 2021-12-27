/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:40:44 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/27 16:52:04 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_set
{
	int				*sort;
	int				*mess;
	int				count;
	int				mid;
	int				mid_num;
	int				left;
}					t_set;

/*
	init_set0:
*/

void	create_sets(t_set *set_a, t_set *set_b, t_set *set_0);
void	init_set0(t_set *set_0, int *set, int argc);
int		*sort_set(int *set, int argc);
void	sort_set_util(int *set_sorted, int argc);
int		*check_initial_set(int argc, char **argv);

/*
	init_setA:
*/

void	init_setA(t_set *set_a, t_set *set_0);
int		*easy_set(t_set *set_0);
int		*easy_sort(int n);
int		check_A_for_sorted(t_set *set_a);

/*
	init_setB:
*/

void	init_setB(t_set *set_a, t_set *set_b);

/*
	move_b_to_a:
*/

void	move_pair_b_to_a(t_set *set_a, t_set *set_b, int max);
void	move_b_to_a(t_set *set_a, t_set *set_b);
void	move_b_to_a_util(t_set *set_a, t_set *set_b, int rbs, int rrbs);
int		find_max(t_set *set_b);
int		find_min(t_set *set_b);

/*
	move_mids_a_to_b:
*/

void	move_portions_to_b(t_set *set_a, t_set *set_b);
void	move_to_b_util(t_set *set_a, t_set *set_b, int pbs);
void	update_set_A(t_set *set_a);
void	last_push_to_b(t_set *set_a, t_set *set_b);
void	last_push_util(t_set *set_a, t_set *set_b, int ras, int rras);

/*
	push_swap:
*/

int		atoi_p_s(char *str);
void	error_occured(const char *msg);
void	check_for_dublicates(int *set, int set_len);

/*
	rotations:
*/

void	ra(t_set *set_a);
void	rb(t_set *set_b);
void	rra(t_set *set_a);
void	rrb(t_set *set_b);

/*
	swap && push:
*/

void	sa(t_set *set_a);
void	sb(t_set *set_b);
void	ss(t_set *set_a, t_set *set_b);
void	pa(t_set *set_a, t_set *set_b);
void	pb(t_set *set_a, t_set *set_b);

/*
	free_memory:
*/
void	free_all(t_set *set_a, t_set *set_b, t_set *set_0);

#endif