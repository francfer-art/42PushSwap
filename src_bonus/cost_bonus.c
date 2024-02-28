/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:36:48 by francfer          #+#    #+#             */
/*   Updated: 2024/02/27 18:11:38 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	number_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	get_cost(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux_a;
	t_node	*aux_b;
	int		size_a;
	int		size_b;

	aux_a = *stack_a;
	aux_b = *stack_b;
	size_a = get_stack_size(aux_a);
	size_b = get_stack_size(aux_b);
	while (aux_b)
	{
		aux_b->cost_b = aux_b->pos;
		if (aux_b->pos > size_b / 2)
			aux_b->cost_b = (size_b - aux_b->pos) * -1;
		aux_b->cost_a = aux_b->target_pos;
		if (aux_b->target_pos > size_a / 2)
			aux_b->cost_a = (size_a - aux_b->target_pos) * -1;
		aux_b = aux_b->next;
	}
}

void	do_cheapest_move(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	aux = *stack_b;
	cheapest = INT_MAX;
	while (aux)
	{
		if (nb_abs(aux->cost_a) + nb_abs(aux->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(aux->cost_b) + nb_abs(aux->cost_a);
			cost_a = aux->cost_a;
			cost_b = aux->cost_b;
		}
		aux = aux->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
