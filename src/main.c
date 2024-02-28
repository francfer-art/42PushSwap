/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:03:56 by francfer          #+#    #+#             */
/*   Updated: 2024/02/20 08:54:05 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

static void	push_swap(t_node **stack_a, t_node **stack_b, int stack_size)
{
	assign_index(*stack_a, stack_size + 1);
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

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

static void	final_clean_down(t_node *a, t_node *b, char *line, char **new)
{
	free_stack(&a);
	free_stack(&b);
	free_list(new);
	free(line);
}

int	main(int args, char **argv)
{
	char	*line;
	char	**new;
	t_node	*stack_a;
	t_node	*stack_b;
	int		stack_size;

	line = NULL;
	if (args < 2)
		return (0);
	else if (args == 2 && !argv[1][0])
		exit_error(NULL, NULL);
	else
		line = getting_line(args, argv);
	new = ft_split(line);
	if (!is_correct_input(new))
	{
		free_list(new);
		exit_error(NULL, NULL);
	}
	stack_b = NULL;
	stack_a = fill_stack_values(new);
	stack_size = get_stack_size(stack_a);
	push_swap(&stack_a, &stack_b, stack_size);
	final_clean_down(stack_a, stack_b, line, new);
	return (0);
}
