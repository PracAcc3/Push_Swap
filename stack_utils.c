/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:11:49 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/09 17:11:49 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min_value;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min_value = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min_value)
		{
			min_value = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long			max_value;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max_value = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max_value)
		{
			max_value = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
