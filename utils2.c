/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 00:00:00 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/09 17:20:33 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push_min_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*min_node;

	current_index(*stack_a);
	min_node = find_min(*stack_a);
	prep_for_push(stack_a, min_node, 'a');
	pb(stack_b, stack_a, false);
}
