/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:12:04 by francfer          #+#    #+#             */
/*   Updated: 2024/01/24 12:18:06 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_node	*fill_stack_values1(int ac, char **av)
{
	t_node		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

t_node	*fill_stack_values(char **av)
{
	t_node		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

void	assign_index(t_node *stack_a, int stack_size)
{
	t_node	*aux;
	t_node	*highest;
	int		value;

	while (--stack_size > 0)
	{
		aux = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (aux)
		{
			if (aux->value == INT_MIN && aux->index == 0)
				aux->index = 1;
			if (aux->value > value && aux->index == 0)
			{
				value = aux->value;
				highest = aux;
				aux = stack_a;
			}
			else
				aux = aux->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
