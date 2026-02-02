# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/25 13:07:56 by mel-yazi          #+#    #+#              #
#    Updated: 2026/02/02 10:42:59 by mel-yazi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_isdigit.c stack.c sorting_strategies.c \
		is_valid_arg.c ft_split.c ft_putstr_fd.c ft_putnbr_fd.c sorting.c \
		helper_functions.c stack_operations.c sorting_moves.c cheapest_move.c \
		sort_three.c

BONUS_DIR = Checker_bonus

SRC_BOUNS = $(addprefix $(BONUS_DIR)/, ft_atoi_checker_bonus.c ft_isdigit_bonus.c ft_putstr_fd_bonus.c ft_strcmp_bonus.c \
	 instructions_bonus.c is_valid_list_bonus.c stack_checker_bonus.c \
	help_functions_bonus.c instructions_help_bonus.c utilitize_bonus.c ft_split_bonus.c) 

OBJS = $(SRC:.c=.o)
OBJ_BOUNS = $(SRC_BOUNS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) 
	cc main.c $(OBJS) -o $(NAME)

%.o : %.c push_swap.h
		@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_DIR)/%.o : $(BONUS_DIR)/%.c  $(BONUS_DIR)/checker_bonus.h
		@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(OBJ_BOUNS) 
	cc Checker_bonus/main_bonus.c  $(OBJ_BOUNS) -o $(CHECKER_NAME)

clean:
	rm -f $(OBJS)
	rm -f $(OBJ_BOUNS)

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER_NAME)

re: fclean all

.PHONY: clean
