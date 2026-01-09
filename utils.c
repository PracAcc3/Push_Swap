/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:46:48 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/09 17:05:14 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_issign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

void	free_argv(char **argv)
{
	int	index;

	index = 0;
	if (!argv)
		return ;
	while (argv[index])
		free(argv[index++]);
	free(argv);
}

int	ps_error(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}
