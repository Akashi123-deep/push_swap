/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 11:57:37 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/25 11:26:32 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	validate_instruction(char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		return ;
	if (ft_strcmp(line, "sb\n") == 0)
		return ;
	if (ft_strcmp(line, "ss\n") == 0)
		return ;
	if (ft_strcmp(line, "pa\n") == 0)
		return ;
	if (ft_strcmp(line, "pb\n") == 0)
		return ;
	if (ft_strcmp(line, "ra\n") == 0)
		return ;
	if (ft_strcmp(line, "rb\n") == 0)
		return ;
	if (ft_strcmp(line, "rr\n") == 0)
		return ;
	if (ft_strcmp(line, "rra\n") == 0)
		return ;
	if (ft_strcmp(line, "rrb\n") == 0)
		return ;
	if (ft_strcmp(line, "rrr\n") == 0)
		return ;
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	execute_instruction(char *line, t_Stack *stack_a, t_Stack *stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		return (sa(stack_a));
	if (ft_strcmp(line, "sb\n") == 0)
		return (sb(stack_b));
	if (ft_strcmp(line, "ss\n") == 0)
		return (ss(stack_a, stack_b));
	if (ft_strcmp(line, "pa\n") == 0)
		return (pa(stack_a, stack_b));
	if (ft_strcmp(line, "pb\n") == 0)
		return (pb(stack_a, stack_b));
	if (ft_strcmp(line, "ra\n") == 0)
		return (ra(stack_a));
	if (ft_strcmp(line, "rb\n") == 0)
		return (rb(stack_b));
	if (ft_strcmp(line, "rr\n") == 0)
		return (rr(stack_a, stack_b));
	if (ft_strcmp(line, "rra\n") == 0)
		return (rra(stack_a));
	if (ft_strcmp(line, "rrb\n") == 0)
		return (rrb(stack_b));
	if (ft_strcmp(line, "rrr\n") == 0)
		return (rrr(stack_a, stack_b));
}

bool	read_line_from_stdin(char *buffer)
{
	int		i;
	ssize_t	bytes;

	i = 0;
	while (i < 5)
	{
		bytes = read(0, &buffer[i], 1);
		if (bytes <= 0)
		{
			buffer[i] = '\0';
			if (i > 0)
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			return (false);
		}
		if (buffer[i] == '\n')
		{
			buffer[i + 1] = '\0';
			return (true);
		}
		i++;
	}
	return (true);
}

void	implement_the_intctructions(t_Stack *stack_a, t_Stack *stack_b)
{
	char	buffer[10];

	while (read_line_from_stdin(buffer) != 0)
	{
		validate_instruction(buffer);
		execute_instruction(buffer, stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;
	int		length;

	if (argc < 2)
		return ((true));
	argv++;
	if (argc == 2)
		argv = ft_split(*argv, ' ');
	else
		argv = mix_arg(argv);
	is_valid_arg(argv);
	length = arg_length(argv);
	stack_a = create_stack(length);
	stack_b = create_stack(length);
	push_items(stack_a, argv);
	implement_the_intctructions(stack_a, stack_b);
	if (!is_stack_sorted(stack_a, stack_b))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	free_list(argv);
	free_the_stack(stack_a);
	free_the_stack(stack_b);
	return (0);
}
