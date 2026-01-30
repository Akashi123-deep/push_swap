/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:24:22 by mel-yazi          #+#    #+#             */
/*   Updated: 2025/12/30 13:25:41 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	pa(t_Stack *stackA, t_Stack *stackB)
{
	if (is_empty(stackB))
		return (false);
	push(stackA, stackB->items[stackB->index]);
	pop(stackB);
	ft_putstr_fd("pa\n", 1);
	return (true);
}

bool	pb(t_Stack *stackA, t_Stack *stackB)
{
	if (is_empty(stackA))
		return (false);
	push(stackB, stackA->items[stackA->index]);
	pop(stackA);
	ft_putstr_fd("pb\n", 1);
	return (true);
}

bool	swap(t_Stack *stack)
{
	int	temp;

	if (stack->index >= 1)
	{
		temp = stack->items[stack->index];
		stack->items[stack->index] = stack->items[stack->index - 1];
		stack->items[stack->index - 1] = temp;
		return (true);
	}
	return (false);
}

bool	rotate(t_Stack *stack)
{
	int	temp;
	int	i;

	if (stack->index >= 1)
	{
		temp = stack->items[stack->index];
		i = stack->index;
		while (i > 0)
		{
			stack->items[i] = stack->items[i - 1];
			i--;
		}
		stack->items[0] = temp;
		return (true);
	}
	return (false);
}

bool	reverse_rotate(t_Stack *stack)
{
	int	temp;
	int	i;

	if (stack->index >= 1)
	{
		temp = stack->items[0];
		i = 0;
		while (i < stack->index)
		{
			stack->items[i] = stack->items[i + 1];
			i++;
		}
		stack->items[stack->index] = temp;
		return (true);
	}
	return (false);
}
