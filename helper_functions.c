/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:26:16 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/17 14:38:12 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Stack	*create_stack_main(int capacity)
{
	t_Stack	*stack;

	if (capacity <= 0)
		return (NULL);
	stack = malloc(sizeof(t_Stack));
	if (!stack)
		return (NULL);
	stack->items = malloc(sizeof(int) * capacity);
	if (!stack->items)
	{
		free(stack);
		return (NULL);
	}
	stack->capacity = capacity;
	stack->index = -1;
	return (stack);
}

bool	push(t_Stack *stack, int item)
{
	if (is_full(stack))
		return (false);
	stack->items[stack->index + 1] = item;
	stack->index++;
	return (true);
}

bool	pop(t_Stack *stack)
{
	if (is_empty(stack))
		return (false);
	stack->index--;
	return (true);
}

int	get_cost(int pos, int len, int *direction)
{
	int	dist_up;
	int	dist_down;

	dist_up = len - pos;
	dist_down = pos + 1;
	if (dist_up <= dist_down)
	{
		*direction = 1;
		return (dist_up);
	}
	*direction = -1;
	return (dist_down);
}

void	bring_to_top(t_Stack *stack, int pos, char name)
{
	int	dir;
	int	cost;

	cost = get_cost(pos, stack->index, &dir);
	while (cost > 0)
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
		cost--;
	}
}
