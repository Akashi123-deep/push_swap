/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 10:59:13 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/30 11:14:18 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_double_rotate(t_Stack *a, t_Stack *b, t_move *m)
{
	while (m->dir_a == m->dir_b && m->cost_a > 0 && m->cost_b > 0)
	{
		if (m->dir_a == 1)
		{
			rotate(a);
			rotate(b);
			ft_putstr_fd("rr\n", 1);
		}
		else
		{
			reverse_rotate(a);
			reverse_rotate(b);
			ft_putstr_fd("rrr\n", 1);
		}
		m->cost_a--;
		m->cost_b--;
	}
}

static void	finish_rotate_a(t_Stack *a, t_move *m)
{
	while (m->cost_a > 0)
	{
		if (m->dir_a == 1)
		{
			rotate(a);
			ft_putstr_fd("ra\n", 1);
		}
		else
		{
			reverse_rotate(a);
			ft_putstr_fd("rra\n", 1);
		}
		m->cost_a--;
	}
}

static void	finish_rotate_b(t_Stack *b, t_move *m)
{
	while (m->cost_b > 0)
	{
		if (m->dir_b == 1)
		{
			rotate(b);
			ft_putstr_fd("rb\n", 1);
		}
		else
		{
			reverse_rotate(b);
			ft_putstr_fd("rrb\n", 1);
		}
		m->cost_b--;
	}
}

void	execute_move(t_Stack *a, t_Stack *b, t_move m)
{
	do_double_rotate(a, b, &m);
	finish_rotate_a(a, &m);
	finish_rotate_b(b, &m);
	pb(a, b);
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
