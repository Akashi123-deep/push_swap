/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 13:08:13 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/30 10:29:21 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static bool	push_items(t_Stack *stack, char **arg)
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

int	main(int argc, char **argv)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;
	size_t	length;

	if (argc < 2)
		return (1);
	argv++;
	if (argc == 2)
		argv = ft_split(*argv, ' ');
	else
		argv = mix_arg(argv);
	is_valid_arg(argv);
	length = arg_length(argv);
	stack_a = create_stack_main(length);
	stack_b = create_stack_main(length);
	push_items(stack_a, argv);
	is_sorted(argv);
	if (length == 5)
		sort_five_elements(stack_a, stack_b);
	else
		sort_the_stack(stack_a, stack_b);
	free_list(argv);
	free_the_stack(stack_a);
	free_the_stack(stack_b);
	return (0);
}
