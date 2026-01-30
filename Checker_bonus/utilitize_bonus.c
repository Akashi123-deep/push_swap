/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitize_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:21:44 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/03 11:37:09 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

bool	is_full(t_Stack *stack)
{
	return (stack->capacity == stack->index + 1);
}

bool	is_empty(t_Stack *stack)
{
	return (stack->index == -1);
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

void	ss(t_Stack *stack_a, t_Stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
