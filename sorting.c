/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:21:01 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/25 10:22:41 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest_greater(t_Stack *a, int val)
{
	int		i;
	int		target_index;
	long	best;

	target_index = -1;
	best = LONG_MAX;
	i = a->index;
	while (i >= 0)
	{
		if (a->items[i] > val && a->items[i] < best)
		{
			best = a->items[i];
			target_index = i;
		}
		i--;
	}
	return (target_index);
}

static int	find_smallest(t_Stack *a)
{
	int		i;
	int		target_index;
	long	best;

	target_index = -1;
	best = LONG_MAX;
	i = a->index;
	while (i >= 0)
	{
		if (a->items[i] < best)
		{
			best = a->items[i];
			target_index = i;
		}
		i--;
	}
	return (target_index);
}

static int	get_target_in_a_for_b(t_Stack *a, int val_b)
{
	int	target;

	target = find_smallest_greater(a, val_b);
	if (target == -1)
		target = find_smallest(a);
	return (target);
}

void	sort_the_stack(t_Stack *stackA, t_Stack *stackB)
{
	t_move	cheapest;
	int		target_in_a;

	if (stackA->index > 3 && !is_empty(stackA))
		pb(stackA, stackB);
	if (stackA->index > 3 && !is_empty(stackA))
		pb(stackA, stackB);
	while (stackA->index > 2)
	{
		cheapest = find_cheapest_move(stackA, stackB);
		execute_move(stackA, stackB, cheapest);
	}
	sort_three(stackA);
	while (stackB->index >= 0)
	{
		target_in_a = get_target_in_a_for_b(stackA,
				stackB->items[stackB->index]);
		bring_to_top(stackA, target_in_a, 'a');
		pa(stackA, stackB);
	}
	rotate_smallest_to_top(stackA, 'a');
}
