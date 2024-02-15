/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:06:27 by francfer          #+#    #+#             */
/*   Updated: 2024/01/05 17:19:03 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_swap(char *line, t_node **stack_a, t_node **stack_b)
{
	if (!(ft_strcmp(line, "sa\n")))
		swap(*stack_a);
	if (!(ft_strcmp(line, "sb\n")))
		swap(*stack_b);
	if (!(ft_strcmp(line, "ss\n")))
	{
		swap(*stack_a);
		swap(*stack_b);
	}
}

void	do_commands(char *line, t_node **stack_a, t_node **stack_b)
{
	do_swap(line, stack_a, stack_b);
	if (!(ft_strcmp(line, "pa\n")))
		push(stack_b, stack_a);
	if (!(ft_strcmp(line, "pb\n")))
		push(stack_a, stack_b);
	if (!(ft_strcmp(line, "ra\n")))
		rotate(stack_a);
	if (!(ft_strcmp(line, "rb\n")))
		rotate(stack_b);
	if (!(ft_strcmp(line, "rr\n")))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	if (!(ft_strcmp(line, "rra\n")))
		rev_rotate(stack_a);
	if (!(ft_strcmp(line, "rrb\n")))
		rev_rotate(stack_b);
	if (!(ft_strcmp(line, "rrr\n")))
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
	}
}

void	commands(t_node *stack_a, t_node *stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
		{
			free(line);
			break ;
		}
		if (check_line(line))
		{
			free(line);
			exit_error(NULL, NULL);
		}
		do_commands(line, &stack_a, &stack_b);
		free(line);
		if (is_sorted(stack_a) && get_stack_size(stack_b) == 0)
			break ;
	}
	print_checker_res(&stack_a, &stack_b);
}
