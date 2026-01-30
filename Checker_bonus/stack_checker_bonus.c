/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checker_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 13:22:01 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/18 12:59:49 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	free_list(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

size_t	arg_length(char **arg)
{
	size_t	length;
	char	**temp;

	length = 0;
	temp = arg;
	while (*temp)
	{
		length++;
		temp++;
	}
	return (length);
}

bool	push_items(t_Stack *stack, char **arg)
{
	char	**end;

	end = arg;
	while (*end)
		end++;
	while (end != arg)
	{
		end--;
		if (!push(stack, ft_atoi(*end)))
			return (false);
	}
	return (true);
}
