/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:13:47 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/09 17:13:47 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **to_stack, t_stack_node **from_stack)
{
	t_stack_node	*node_to_push;

	if (!*from_stack)
		return ;
	node_to_push = *from_stack;
	*from_stack = (*from_stack)->next;
	if (*from_stack)
		(*from_stack)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*to_stack)
	{
		*to_stack = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *to_stack;
		node_to_push->next->prev = node_to_push;
		*to_stack = node_to_push;
	}
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b, bool silent)
{
	push(stack_a, stack_b);
	if (!silent)
		ft_printf("pa\n");
}

void	pb(t_stack_node **stack_b, t_stack_node **stack_a, bool silent)
{
	push(stack_b, stack_a);
	if (!silent)
		ft_printf("pb\n");
}
