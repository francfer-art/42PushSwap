/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:03:56 by francfer          #+#    #+#             */
/*   Updated: 2024/02/15 21:07:34 by francfer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static void	free_list(char **list)
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

int	main(int args, char **argv)
{
	char	*line = NULL;
	char	**new;
	t_node	*stack_a;
	t_node	*stack_b;
	int		stack_size;
	
	if (args < 2)
		return (0);
	else if (args == 2 && !argv[1][0])
		exit_error(NULL, NULL);
	else
		line = getting_line(args, argv);
	new = ft_split(line);
	if (!is_correct_input(new))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(new);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free_list(new);
	free(line);
	return (0);
}
