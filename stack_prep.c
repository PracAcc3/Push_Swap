/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:30:52 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/08 15:30:52 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack,
					t_stack_node *node_to_top,
					char stack_id)
{
	while (*stack != node_to_top)
	{
		if (stack_id == 'a')
		{
			if (node_to_top->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_id == 'b')
		{
			if (node_to_top->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
