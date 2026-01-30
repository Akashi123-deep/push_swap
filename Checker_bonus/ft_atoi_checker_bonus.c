/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_checker_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 13:08:08 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/02 15:22:41 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	is_whitespace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

static int	is_it_overflow(const char *temp_str, int sign)
{
	long long	result;

	result = 0;
	while (*temp_str && ft_isdigit(*temp_str))
	{
		if (result > (9223372036854775807 - (*temp_str - '0')) / 10)
		{
			if (sign == 1)
				return (1);
			if (sign == -1)
				return (-1);
		}
		result = result * 10 + (*temp_str - '0');
		temp_str++;
	}
	return (0);
}

static char	*is_valid(const char *temp_str, int *sign)
{
	if (*temp_str == '-' && ft_isdigit(*(temp_str + 1)))
	{
		*sign = -1;
		temp_str++;
	}
	if (*temp_str == '+' && ft_isdigit(*(temp_str + 1)))
	{
		*sign = 1;
		temp_str++;
	}
	return ((char *)temp_str);
}

long long	ft_atoi(const char *str)
{
	const char	*temp_str;
	long long	result;
	int			sign;
	int			over_flow;

	temp_str = str;
	sign = 1;
	result = 0;
	while (is_whitespace(*temp_str))
	{
		temp_str++;
	}
	temp_str = is_valid(temp_str, &sign);
	over_flow = is_it_overflow(temp_str, sign);
	if (over_flow == 1)
		return (-1);
	if (over_flow == -1)
		return (0);
	while (*temp_str && ft_isdigit(*temp_str))
	{
		result = result * 10 + (*temp_str - '0');
		temp_str++;
	}
	return (result * sign);
}
