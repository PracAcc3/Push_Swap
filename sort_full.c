/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_full.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:30:43 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/08 15:30:43 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both_stacks(t_stack_node **stack_a,
				t_stack_node **stack_b,
				t_stack_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node
		&& *stack_a != cheapest_node)
		rr(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}

static void	rev_rotate_both_stacks(t_stack_node **stack_a,
					t_stack_node **stack_b,
					t_stack_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node
		&& *stack_a != cheapest_node)
		rrr(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}

static void	push_cheapest_a_to_b(t_stack_node **stack_a,
					t_stack_node **stack_b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both_stacks(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both_stacks(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack_b, stack_a, false);
}

static void	rotate_min_to_top(t_stack_node **stack_a)
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

void	sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	remaining_a;

	remaining_a = stack_len(*stack_a);
	if (remaining_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a, false);
	if (remaining_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a, false);
	while (remaining_a-- > 3 && !stack_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		push_cheapest_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		prep_for_push(stack_a, (*stack_b)->target_node, 'a');
		pa(stack_a, stack_b, false);
	}
	current_index(*stack_a);
	rotate_min_to_top(stack_a);
}