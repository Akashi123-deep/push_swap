/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:09:40 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/02/02 10:34:00 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(char *message, char **list)
{
	ft_putstr_fd(message, 2);
	free_list(list);
	exit(1);
}

static bool	is_duplicates(char **arg)
{
	char	**temp_i;
	char	**temp_j;

	temp_i = arg;
	while (*temp_i)
	{
		temp_j = temp_i + 1;
		while (*temp_j)
		{
			if (ft_atoi(*temp_i) == ft_atoi(*temp_j))
				return (true);
			temp_j++;
		}
		temp_i++;
	}
	return (false);
}

static bool	is_valid_nbr(char **arg)
{
	char	**temp_str;
	char	*temp_char;

	temp_str = arg;
	while (*temp_str)
	{
		temp_char = *temp_str;
		if (*temp_char == '-' || *temp_char == '+')
			temp_char++;
		if (!*temp_char)
			return (false);
		while (*temp_char)
		{
			if (!ft_isdigit(*temp_char))
				return (false);
			temp_char++;
		}
		temp_str++;
	}
	return (true);
}

static bool	is_over_flow(char *temp)
{
	long long	result;
	int			digit;

	result = 0;
	if (*temp == '-' || *temp == '+')
		temp++;
	while (*temp)
	{
		digit = *temp - '0';
		if (result > LONG_MAX / 10 || (result == LONG_MAX / 10
				&& digit > LONG_MAX % 10))
			return (true);
		result = result * 10 + digit;
		temp++;
	}
	return (false);
}

bool	is_valid_arg(char **temp)
{
	long long	number;
	char **start;

	start = temp;
	if (!*temp)
		error_message("Error\n", start);
	while (*temp)
	{
		number = ft_atoi(*temp);
		if (number > INT_MAX || number < INT_MIN)
			error_message("Error\n", start);
		if (is_duplicates(temp))
			error_message("Error\n", start);
		if (!is_valid_nbr(temp))
			error_message("Error\n", start);
		if (is_over_flow(*temp))
			error_message("Error\n", start);
		temp++;
	}
	return (true);
}
