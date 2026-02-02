/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:24:58 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/30 19:15:40 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_Stack
{
	int		*items;
	int		index;
	int		capacity;
}			t_Stack;

void		free_the_things(t_Stack *stack_a, t_Stack *stack_b, char **list);
void		error_message(char *message, char **list);
char		**mix_arg(char **arg);
void		free_list(char **arr);
char		**ft_split(char const *s, char c);
bool		pop(t_Stack *stack);
bool		is_stack_sorted(t_Stack *stack_a, t_Stack *stack_b);
bool		contain_new_line(char *buffer);
bool		is_empty(t_Stack *stack);
int			ft_isdigit(int c);
bool		push(t_Stack *stack, int item);
bool		is_valid_arg(char **temp);
bool		push_items(t_Stack *stack, char **arg);
size_t		arg_length(char **arg);
void		free_the_stack(t_Stack *stack);
t_Stack		*create_stack(int capacity);
long long	ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_strcmp(const char *s1, const char *s2);
void		pa(t_Stack *stackA, t_Stack *stackB);
void		pb(t_Stack *stackA, t_Stack *stackB);
void		sa(t_Stack *stack_a);
void		sb(t_Stack *stack_b);
void		ss(t_Stack *stack_a, t_Stack *stack_b);
void		ra(t_Stack *stack_a);
void		rb(t_Stack *stack_b);
void		rr(t_Stack *stack_a, t_Stack *stack_b);
void		rra(t_Stack *stack_a);
void		rrb(t_Stack *stack_b);
void		rrr(t_Stack *stack_a, t_Stack *stack_b);

#endif