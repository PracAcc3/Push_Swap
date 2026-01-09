/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:13:54 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/09 17:13:54 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	prepare_args(int argc, char **argv,
					char ***split_args, char ***input_args)
{
	if (argc == 1)
		return (0);
	if (argc == 2 && !argv[1][0])
	{
		return (ps_error());
	}
	if (argc == 2)
	{
		*split_args = split(argv[1], ' ');
		if (!*split_args)
		{
			return (ps_error());
		}
		*input_args = *split_args;
		return (2);
	}
	*input_args = argv + 1;
	return (2);
}

static void	sort_if_needed(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	len;

	if (stack_sorted(*stack_a))
		return ;
	len = stack_len(*stack_a);
	if (len == 2)
		sa(stack_a, false);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_four(stack_a, stack_b);
	else if (len == 5)
		sort_five(stack_a, stack_b);
	else
		sort_stacks(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			**split_args;
	char			**input_args;
	int				parse_status;

	stack_a = NULL;
	stack_b = NULL;
	split_args = NULL;
	input_args = NULL;
	parse_status = prepare_args(argc, argv, &split_args, &input_args);
	if (parse_status == 0)
		return (0);
	if (parse_status == 1)
		return (1);
	init_stack_a(&stack_a, input_args, (argc == 2));
	sort_if_needed(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_argv(split_args);
	return (0);
}
