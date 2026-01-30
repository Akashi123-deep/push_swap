/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:22:12 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/03 13:02:00 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_Stack *stack_a)
{
	int	temp;

	if (stack_a->index < 1)
		return ;
	temp = stack_a->items[stack_a->index];
	stack_a->items[stack_a->index] = stack_a->items[stack_a->index - 1];
	stack_a->items[stack_a->index - 1] = temp;
}

void	sb(t_Stack *stack_b)
{
	int	temp;

	if (stack_b->index < 1)
		return ;
	temp = stack_b->items[stack_b->index];
	stack_b->items[stack_b->index] = stack_b->items[stack_b->index - 1];
	stack_b->items[stack_b->index - 1] = temp;
}

void	ra(t_Stack *stack_a)
{
	int	temp;
	int	i;

	if (stack_a->index < 1)
		return ;
	temp = stack_a->items[stack_a->index];
	i = stack_a->index;
	while (i > 0)
	{
		stack_a->items[i] = stack_a->items[i - 1];
		i--;
	}
	stack_a->items[0] = temp;
}

void	rb(t_Stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_b->index < 1)
		return ;
	temp = stack_b->items[stack_b->index];
	i = stack_b->index;
	while (i > 0)
	{
		stack_b->items[i] = stack_b->items[i - 1];
		i--;
	}
	stack_b->items[0] = temp;
}

void	rr(t_Stack *stack_a, t_Stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
