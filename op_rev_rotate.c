/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:30:25 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/08 15:30:25 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*tail_node;

	if (!*stack || !(*stack)->next)
		return ;
	tail_node = find_last(*stack);
	tail_node->prev->next = NULL;
	tail_node->next = *stack;
	tail_node->prev = NULL;
	*stack = tail_node;
	tail_node->next->prev = tail_node;
}

void	rra(t_stack_node **stack_a, bool silent)
{
	rev_rotate(stack_a);
	if (!silent)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **stack_b, bool silent)
{
	rev_rotate(stack_b);
	if (!silent)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool silent)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (!silent)
		ft_printf("rrr\n");
}