/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:04:15 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/09 17:04:19 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate_both_stacks(t_stack_node **stack_a,
			t_stack_node **stack_b,
			t_stack_node *node)
{
	while (*stack_b != node->target_node && *stack_a != node)
		rr(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}

void	ps_rev_rotate_both_stacks(t_stack_node **stack_a,
			t_stack_node **stack_b,
			t_stack_node *node)
{
	while (*stack_b != node->target_node && *stack_a != node)
		rrr(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}

void	ps_push_cheapest_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*node;

	node = get_cheapest(*stack_a);
	if (node->above_median && node->target_node->above_median)
		ps_rotate_both_stacks(stack_a, stack_b, node);
	else if (!node->above_median && !node->target_node->above_median)
		ps_rev_rotate_both_stacks(stack_a, stack_b, node);
	prep_for_push(stack_a, node, 'a');
	prep_for_push(stack_b, node->target_node, 'b');
	pb(stack_b, stack_a, false);
}

void	ps_rotate_min_to_top(t_stack_node **stack_a)
{
	t_stack_node	*min_node;

	min_node = find_min(*stack_a);
	while (*stack_a != min_node)
	{
		if (min_node->above_median)
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}
