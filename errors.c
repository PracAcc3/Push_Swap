/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:30:15 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/08 15:30:15 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *token)
{
	if (!(*token == '+'
			|| *token == '-'
			|| (*token >= '0' && *token <= '9')))
		return (1);
	if ((*token == '+'
			|| *token == '-')
		&& !(token[1] >= '0' && token[1] <= '9'))
		return (1);
	while (*++token)
	{
		if (!(*token >= '0' && *token <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *stack, int nbr)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nbr == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}