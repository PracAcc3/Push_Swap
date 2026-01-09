/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_full.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:12:47 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/09 17:12:47 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ps_push_cheapest_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		prep_for_push(stack_a, (*stack_b)->target_node, 'a');
		pa(stack_a, stack_b, false);
	}
	current_index(*stack_a);
	ps_rotate_min_to_top(stack_a);
}
