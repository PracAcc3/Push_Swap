/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:12:22 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/09 17:12:22 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (ft_issign(*s))
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = ft_calloc(1, sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->nbr = nbr;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

static void	parse_error(t_stack_node **stack_a, char **argv,
					bool free_args_on_error)
{
	if (free_args_on_error)
		free_argv(argv);
	free_errors(stack_a);
}

void	init_stack_a(t_stack_node **stack_a, char **argv,
					bool free_args_on_error)
{
	long	number;
	int		index;

	index = 0;
	while (argv[index])
	{
		if (error_syntax(argv[index]))
			parse_error(stack_a, argv, free_args_on_error);
		number = ft_atol(argv[index]);
		if (number > INT_MAX || number < INT_MIN)
			parse_error(stack_a, argv, free_args_on_error);
		if (error_duplicate(*stack_a, (int)number))
			parse_error(stack_a, argv, free_args_on_error);
		append_node(stack_a, (int)number);
		index++;
	}
}
