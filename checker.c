/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:05:46 by francfer          #+#    #+#             */
/*   Updated: 2024/01/05 17:18:50 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*getting_line(int args, char **argv)
{
	int		i;
	char	*line;

	i = 1;
	while (i < args)
	{
		line = ft_strjoin(line, argv[i]);
		if (!line)
		{
			free(line);
			exit(1);
		}
		line = ft_strjoin(line, " ");
		if (!line)
		{
			free(line);
			exit(1);
		}
		i++;
	}
	return (line);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	check_line(char *line)
{
	if (!(ft_strcmp(line, "sa\n")))
		return (0);
	if (!(ft_strcmp(line, "sb\n")))
		return (0);
	if (!(ft_strcmp(line, "ss\n")))
		return (0);
	if (!(ft_strcmp(line, "pa\n")))
		return (0);
	if (!(ft_strcmp(line, "pb\n")))
		return (0);
	if (!(ft_strcmp(line, "ra\n")))
		return (0);
	if (!(ft_strcmp(line, "rb\n")))
		return (0);
	if (!(ft_strcmp(line, "rr\n")))
		return (0);
	if (!(ft_strcmp(line, "rra\n")))
		return (0);
	if (!(ft_strcmp(line, "rrb\n")))
		return (0);
	if (!(ft_strcmp(line, "rrr\n")))
		return (0);
	return (1);
}

void	print_checker_res(t_node **stack_a, t_node **stack_b)
{
	if (is_sorted(*stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (*stack_a)
		free_stack(stack_a);
	if (*stack_b)
		free_stack(stack_b);
}

int	main(int args, char **argv)
{
	char	*line;
	char	**new;
	t_node	*stack_a;
	t_node	*stack_b;

	if (args < 2)
		return (0);
	else
		line = getting_line(args, argv);
	new = ft_split(line);
	if (!is_correct_input(new))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(new);
	assign_index(stack_a, get_stack_size(stack_a) + 1);
	commands(stack_a, stack_b);
	return (0);
}
