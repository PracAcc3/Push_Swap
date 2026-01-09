/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:30:38 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/08 15:30:38 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	index;
	int	median_index;

	index = 0;
	if (!stack)
		return ;
	median_index = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = index;
		stack->above_median = (index <= median_index);
		stack = stack->next;
		index++;
	}
}

static void	set_target_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*cursor_b;
	t_stack_node	*target_node;
	long			best_match_value;

	while (stack_a)
	{
		best_match_value = LONG_MIN;
		cursor_b = stack_b;
		while (cursor_b)
		{
			if (cursor_b->nbr < stack_a->nbr
				&& cursor_b->nbr > best_match_value)
			{
				best_match_value = cursor_b->nbr;
				target_node = cursor_b;
			}
			cursor_b = cursor_b->next;
		}
		if (best_match_value == LONG_MIN)
			stack_a->target_node = find_max(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

static void	cost_analysis_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;
	t_stack_node	*cursor;

	if (!stack)
		return ;
	cursor = stack;
	while (cursor)
	{
		cursor->cheapest = false;
		cursor = cursor->next;
	}
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}