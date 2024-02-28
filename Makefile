# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 11:47:55 by francfer          #+#    #+#              #
#    Updated: 2024/02/27 18:15:56 by francfer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
SRC_DIR_BONUS = src_bonus
FILES = cost.c init.c input_check_utils.c input_check.c main.c move.c \
        position.c push.c rotate.c rrotate.c split.c stack_utils.c swap.c utils.c \
		sort_3.c sort.c get_next_line.c get_next_line_utils.c
FILES_BONUS = cost_bonus.c init_bonus.c input_check_utils_bonus.c input_check_bonus.c \
		move_bonus.c position_bonus.c push_bonus.c rotate_bonus.c rrotate_bonus.c \
		split_bonus.c stack_utils_bonus.c swap_bonus.c utils_bonus.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c checker_bonus.c \
		checker1_bonus.c
OBJS = $(addprefix $(SRC_DIR)/, $(FILES:.c=.o))
OBJS_BONUS = $(addprefix $(SRC_DIR_BONUS)/, $(FILES_BONUS:.c=.o))
INCS = -I push_swap.h
INCS_BONUS = -I push_swap_bonus.h

COLOUR_PURPLE=\033[0;32m
COLOUR_PURPLE=\033[0;35m
COLOUR_END=\033[0m

all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(SRC_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS_BONUS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(COLOUR_PURPLE) Push_swap ready! $(COLOUR_END)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo "$(COLOUR_PURPLE) Checker ready! $(COLOUR_END)"

n:
	norminette
	
clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@echo "$(COLOUR_PURPLE) Cleaning da corps! $(COLOUR_END)"

fclean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "$(COLOUR_PURPLE) Fcleaning da corps! $(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re bonus n

