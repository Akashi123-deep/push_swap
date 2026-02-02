/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_strategies.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:42:55 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/02/02 10:11:40 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(char **str)
{
	char	**temp;

	temp = str;
	while (*temp && *(temp + 1))
	{
		if (ft_atoi(*temp) > ft_atoi(*(temp + 1)))
			return (false);
		temp++;
	}
	return(true);
}

static int	find_the_smallest_number(t_Stack *stack)
{
	int	i;
	int	smallest;
	int	smallest_index;

	if (is_empty(stack))
		return (-1);
	smallest = stack->items[stack->index];
	smallest_index = stack->index;
	i = stack->index - 1;
	while (i >= 0)
	{
		if (stack->items[i] < smallest)
		{
			smallest = stack->items[i];
			smallest_index = i;
		}
		i--;
	}
	return (smallest_index);
}

static void	do_rotate(t_Stack *stack, int dir, char name)
{
	if (dir == 1)
	{
		rotate(stack);
		if (name == 'a')
			ft_putstr_fd("ra\n", 1);
		else
			ft_putstr_fd("rb\n", 1);
	}
	else
	{
		reverse_rotate(stack);
		if (name == 'a')
			ft_putstr_fd("rra\n", 1);
		else
			ft_putstr_fd("rrb\n", 1);
	}
}

void	rotate_smallest_to_top(t_Stack *stack, char name)
{
	int	pos;
	int	dir;
	int	cost;

	pos = find_the_smallest_number(stack);
	cost = get_cost(pos, stack->index, &dir);
	while (cost > 0)
	{
		do_rotate(stack, dir, name);
		cost--;
	}
}

void	sort_five_elements(t_Stack *stackA, t_Stack *stackB)
{
	while (stackA->index > 2)
	{
		rotate_smallest_to_top(stackA, 'a');
		pb(stackA, stackB);
	}
	sort_three(stackA);
	pa(stackA, stackB);
	pa(stackA, stackB);
}
