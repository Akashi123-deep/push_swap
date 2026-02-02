/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 13:08:17 by mel-yazi          #+#    #+#             */
/*   Updated: 2026/01/30 18:53:46 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_Stack
{
	int		*items;
	int		index;
	int		capacity;
}			t_Stack;

typedef struct s_move
{
	int		idx_a;
	int		idx_b;
	int		cost_a;
	int		cost_b;
	int		dir_a;
	int		dir_b;
	int		total_cost;
}			t_move;

void		error_message(char *message, char **list);
void		free_list(char **arr);
void		copy_to(char **dest, char **src);
size_t		mix_arg_count(char **arg);
char		**mix_arg(char **arg);
void		sort_five_elements(t_Stack *stackA, t_Stack *stackB);
size_t		arg_length(char **arg);
int			get_cost(int pos, int len, int *direction);
void		execute_move(t_Stack *a, t_Stack *b, t_move move);
void		bring_to_top(t_Stack *stack, int pos, char name);
void		rotate_smallest_to_top(t_Stack *stack, char name);
void		sort_three(t_Stack *stackA);
t_move		find_cheapest_move(t_Stack *a, t_Stack *b);
bool		is_empty(t_Stack *stack);
bool		pa(t_Stack *stackA, t_Stack *stackB);
bool		pb(t_Stack *stackA, t_Stack *stackB);
bool		pop(t_Stack *stack);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
void		sort_the_stack(t_Stack *stackA, t_Stack *stackB);
char		**ft_split(char const *s, char c);
bool		is_valid_arg(char **temp);
int			ft_isdigit(int c);
bool		is_sorted(char **str);
bool		reverse_rotate(t_Stack *stack);
bool		rotate(t_Stack *stack);
bool		swap(t_Stack *stack);
bool		is_full(t_Stack *stack);
void		free_the_stack(t_Stack *stack);
bool		push(t_Stack *stack, int item);
t_Stack		*create_stack_main(int capacity);
void		ft_putstr_fd(char *s, int fd);
long long	ft_atoi(const char *str);
int			ft_isdigit(int c);

#endif