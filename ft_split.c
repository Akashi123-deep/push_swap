/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:25:15 by mel-yazi          #+#    #+#             */
/*   Updated: 2025/12/28 10:43:40 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_copy_until(char *result, const char *str, char until)
{
	while (*str && *str != until)
		*result++ = *str++;
	*result = '\0';
}

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static void	free_all(char **arr)
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

static int	main_logic(char const *s, char c, char **result)
{
	size_t		word_len;
	const char	*word_start;

	while (*s)
	{
		if (*s != c)
		{
			word_start = s;
			word_len = 0;
			while (*s && *s != c)
			{
				word_len++;
				s++;
			}
			*result = malloc(word_len + 1);
			if (!*result)
				return (0);
			ft_copy_until(*result, word_start, c);
			result++;
		}
		else
			s++;
	}
	*result = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!main_logic(s, c, result))
	{
		free_all(result);
		return (NULL);
	}
	return (result);
}
