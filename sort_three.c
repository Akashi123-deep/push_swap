/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:53:16 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/18 13:04:38 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(int top, int mid, int bot)
{
	int	max;

	max = top;
	if (mid > max)
		max = mid;
	if (bot > max)
		max = bot;
	return (max);
}

void	sort_three(t_Stack *a)
{
	int	top;
	int	mid;
	int	max;

	top = a->items[a->index];
	mid = a->items[a->index - 1];
	max = find_max(top, mid, a->items[a->index - 2]);
	if (top == max)
	{
		rotate(a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (mid == max)
	{
		reverse_rotate(a);
		ft_putstr_fd("rra\n", 1);
	}
	if (a->items[a->index] > a->items[a->index - 1])
	{
		swap(a);
		ft_putstr_fd("sa\n", 1);
	}
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

void	copy_to(char **dest, char **src)
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
