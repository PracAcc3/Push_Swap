#include "push_swap.h"

static void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

static char	**normalize_args(int argc, char **argv)
{
	char	**split_args;

	split_args = NULL;
	if (argc == 2)
		split_args = split(argv[1], ' ');
	return (split_args);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			**split_args;
	char			**input_args;

	stack_a = NULL;
	stack_b = NULL;
	split_args = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
	{
		split_args = normalize_args(argc, argv);
		if (!split_args)
			return (0);
		input_args = split_args;
	}
	else
		input_args = argv + 1;
	init_stack_a(&stack_a, input_args);
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a, false);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_argv(split_args);
	return (0);
}