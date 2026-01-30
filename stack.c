/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:18:52 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/25 10:22:58 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Stack	*create_stack(int capacity)
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

void	free_the_stack(t_Stack *stack)
{
	free(stack->items);
	free(stack);
}

bool	is_full(t_Stack *stack)
{
	return (stack->capacity == stack->index + 1);
}

bool	is_empty(t_Stack *stack)
{
	return (stack->index == -1);
}

void	free_temp(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}
