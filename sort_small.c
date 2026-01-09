/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:12:37 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/09 17:12:37 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **stack_a)
{
	t_stack_node	*max_node;

	max_node = find_max(*stack_a);
	if (max_node == *stack_a)
		ra(stack_a, false);
	else if ((*stack_a)->next == max_node)
		rra(stack_a, false);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a, false);
}

void	sort_four(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ps_push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b, false);
}

void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ps_push_min_to_b(stack_a, stack_b);
	ps_push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b, false);
	pa(stack_a, stack_b, false);
}
