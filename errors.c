/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:14:02 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/09 17:14:02 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *token)
{
	if (!(*token == '+' || ft_issign(*token) || (ft_isdigit(*token))))
		return (1);
	if ((ft_issign(*token))
		&& !(ft_isdigit(token[1])))
		return (1);
	while (*++token)
	{
		if (!(ft_isdigit(*token)))
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
	ft_putendl_fd("Error", 2);
	exit(1);
}
