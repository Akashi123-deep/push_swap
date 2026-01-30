/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_help_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:20:19 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/03 13:01:53 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pa(t_Stack *stackA, t_Stack *stackB)
{
	if (is_empty(stackB))
		return ;
	if (push(stackA, stackB->items[stackB->index]))
		pop(stackB);
}

void	pb(t_Stack *stackA, t_Stack *stackB)
{
	if (is_empty(stackA))
		return ;
	if (push(stackB, stackA->items[stackA->index]))
		pop(stackA);
}

void	rra(t_Stack *stack_a)
{
	int	temp;
	int	i;

	if (stack_a->index < 1)
		return ;
	temp = stack_a->items[0];
	i = 0;
	while (i < stack_a->index)
	{
		stack_a->items[i] = stack_a->items[i + 1];
		i++;
	}
	stack_a->items[stack_a->index] = temp;
}

void	rrb(t_Stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_b->index < 1)
		return ;
	temp = stack_b->items[0];
	i = 0;
	while (i < stack_b->index)
	{
		stack_b->items[i] = stack_b->items[i + 1];
		i++;
	}
	stack_b->items[stack_b->index] = temp;
}

void	rrr(t_Stack *stack_a, t_Stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
