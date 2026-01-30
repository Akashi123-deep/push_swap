/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:29:11 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/30 11:12:57 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

bool	is_stack_sorted(t_Stack *stack_a, t_Stack *stack_b)
{
	int	i;

	if (!is_empty(stack_b))
		return (false);
	i = stack_a->index;
	while (i > 0)
	{
		if (stack_a->items[i] > stack_a->items[i - 1])
			return (false);
		i--;
	}
	return (true);
}

static bool	contain_space(char *c)
{
	while (*c)
	{
		if (*c == 32)
			return (true);
		c++;
	}
	return (false);
}

static void	copy_to(char **dest, char **src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
}

size_t	mix_arg_count(char **arg)
{
	size_t	count;
	char	**temp;

	count = 0;
	while (*arg)
	{
		if (contain_space(*arg))
		{
			temp = ft_split(*arg, ' ');
			count = count + arg_length(temp);
			free_list(temp);
		}
		else
			count++;
		arg++;
	}
	return (count);
}

char	**mix_arg(char **arg)
{
	char	**result;
	char	**start;
	char	**temp;

	result = malloc((mix_arg_count(arg) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	start = result;
	while (*arg)
	{
		temp = ft_split(*arg, ' ');
		if (!*temp)
		{
			free_list(start);
			error_message("Error\n", temp);
		}
		copy_to(result, temp);
		free(temp);
		while (*result)
			result++;
		arg++;
	}
	*result = NULL;
	return (start);
}
