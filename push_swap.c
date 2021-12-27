/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:40:37 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/24 23:53:33 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Atoi for push_swap: this function transforms arguments from string to integer 
	as uses 
*/

int	atoi_p_s(char *str)
{
	long int	num;
	int			sign;
	int			i;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			error_occured("Error\n");
		num = num * 10 + str[i++] - '0';
		if (num * sign > 2147483647 || num * sign < -2147483648)
			error_occured("Error\n");
	}
	return ((int)(num * sign));
}

void	error_occured(const char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		write(2, &msg[i], 1);
		i++;
	}
	exit(0);
}

/*
	Make sure that all our numbers in set_A are unique and not repeated
*/

void	check_for_dublicates(int *set, int set_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < set_len - 1)
	{
		j = i + 1;
		while (j < set_len - 1)
		{
			if (set[i] == set[j])
				error_occured("Error\n");
			++j;
		}
		++i;
	}
}

/*
	Main:
	Parse arguments and make sure that we got valid set
	Initialize sets
	Pre-sort: Move numbers from A to B until A is sorted or has 2 numbers remaining
	Final-sort: Move valuse back from b to a by searching highest
	pair in B and always keep set_A sorted
	Done!
*/

int	main(int argc, char **argv)
{
	int		*set;
	t_set	set_0;
	t_set	set_a;
	t_set	set_b;
	int		i;

	i = 1;
	if (argc < 2)
		error_occured("Error\n");
	set = check_initial_set(argc, argv);
	check_for_dublicates(set, argc);
	create_sets(&set_a, &set_b, &set_0);
	init_set0(&set_0, set, argc);
	init_setA(&set_a, &set_0);
	init_setB(&set_a, &set_b);
	i = check_A_for_sorted(&set_a);
	while (i != 0)
	{
		move_portions_to_b(&set_a, &set_b);
		i = check_A_for_sorted(&set_a);
	}
	move_b_to_a(&set_a, &set_b);
}
