/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:12:59 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/09 17:12:59 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*cursor_a;
	t_stack_node	*target_node;
	long			best_match_value;

	while (stack_b)
	{
		best_match_value = LONG_MAX;
		cursor_a = stack_a;
		while (cursor_a)
		{
			if (cursor_a->nbr > stack_b->nbr
				&& cursor_a->nbr < best_match_value)
			{
				best_match_value = cursor_a->nbr;
				target_node = cursor_a;
			}
			cursor_a = cursor_a->next;
		}
		if (best_match_value == LONG_MAX)
			stack_b->target_node = find_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_nodes_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
