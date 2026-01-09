/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:13:31 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/09 17:13:31 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*tail_node;

	if (!*stack || !(*stack)->next)
		return ;
	tail_node = find_last(*stack);
	tail_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tail_node->next->prev = tail_node;
	tail_node->next->next = NULL;
}

void	ra(t_stack_node **stack_a, bool silent)
{
	rotate(stack_a);
	if (!silent)
		ft_printf("ra\n");
}

void	rb(t_stack_node **stack_b, bool silent)
{
	rotate(stack_b);
	if (!silent)
		ft_printf("rb\n");
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, bool silent)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!silent)
		ft_printf("rr\n");
}
