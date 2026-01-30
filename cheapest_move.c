/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:24:40 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/04 10:48:55 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_largest_smaller(t_Stack *b, int val, int find_max)
{
	int		i;
	int		target_index;
	long	best;

	target_index = -1;
	best = LONG_MIN;
	i = b->index;
	while (i >= 0)
	{
		if (!find_max && b->items[i] < val && b->items[i] > best)
		{
			best = b->items[i];
			target_index = i;
		}
		else if (find_max && b->items[i] > best)
		{
			best = b->items[i];
			target_index = i;
		}
		i--;
	}
	return (target_index);
}

static int	get_target_in_b(t_Stack *b, int val_a)
{
	int	target_index;

	target_index = find_largest_smaller(b, val_a, 0);
	if (target_index == -1)
		target_index = find_largest_smaller(b, val_a, 1);
	return (target_index);
}

static int	total_cost(t_move *m)
{
	if (m->dir_a == m->dir_b)
	{
		if (m->cost_a > m->cost_b)
			return (m->cost_a);
		else
			return (m->cost_b);
	}
	return (m->cost_a + m->cost_b);
}

static void	move_cost(t_Stack *a, t_Stack *b, t_move *m)
{
	m->idx_b = get_target_in_b(b, a->items[m->idx_a]);
	m->cost_a = get_cost(m->idx_a, a->index, &m->dir_a);
	m->cost_b = get_cost(m->idx_b, b->index, &m->dir_b);
	m->total_cost = total_cost(m);
}

t_move	find_cheapest_move(t_Stack *a, t_Stack *b)
{
	t_move	best;
	t_move	current;
	int		i;

	best.total_cost = INT_MAX;
	i = a->index;
	while (i >= 0)
	{
		current.idx_a = i;
		move_cost(a, b, &current);
		if (current.total_cost < best.total_cost)
			best = current;
		i--;
	}
	return (best);
}
