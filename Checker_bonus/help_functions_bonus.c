/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:29:11 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/02/02 10:39:15 by mel-yazi         ###   ########.fr       */
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
	char	**temp;
	int		i;
	int		j;

	result = malloc((mix_arg_count(arg) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*arg)
	{
		temp = ft_split(*arg, ' ');
		if (!temp || !*temp)
		{
			if (temp)
				free(temp);
			result[i] = NULL;
			error_message("Error\n", result);
		}
		j = 0;
		while (temp[j])
		{
			result[i++] = temp[j++];
		}
		free(temp);
		arg++;
	}
	result[i] = NULL;
	return (result);
}
