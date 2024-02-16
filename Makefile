# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 11:47:55 by francfer          #+#    #+#              #
#    Updated: 2024/02/16 17:33:42 by francfer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FILES = cost.c init.c input_check_utils.c input_check.c main.c move.c \
        position.c push.c rotate.c rrotate.c split.c stack_utils.c swap.c utils.c \
		sort_3.c sort.c get_next_line.c get_next_line_utils.c
FILES_BONUS = cost.c init.c input_check_utils.c input_check.c move.c \
        position.c push.c rotate.c rrotate.c split.c stack_utils.c swap.c utils.c \
		sort_3.c sort.c get_next_line.c get_next_line_utils.c checker.c \
		checker1.c
OBJS = $(FILES:.c=.o)
OBJS_BONUS = $(FILES_BONUS:.c=.o)
INCS = -I push_swap.h

COLOUR_GREEN=\033[0;32m
COLOUR_YELLOW=\033[1;33m
COLOUR_RED=\033[0;31m
COLOUR_END=\033[0m

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(COLOUR_GREEN)✅ PUSH_SWAP READY ✅ $(COLOUR_END)"

bonus: $(NAME_BONUS)
$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo "$(COLOUR_GREEN)✅ CHECKER READY ✅ $(COLOUR_END)"

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@echo "$(COLOUR_RED)🤡 CLEANING DA CORPS 🤡 $(COLOUR_END)"

fclean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "$(COLOUR_YELLOW)🤡 FCLEANING DA CORPS 🤡 $(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re bonus
