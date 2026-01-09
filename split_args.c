/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:12:29 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/09 17:12:29 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split(char *input, char delimiter)
{
	char	**tokens;

	if (!input)
		return (NULL);
	tokens = ft_split(input, delimiter);
	if (!tokens)
		return (NULL);
	if (!tokens[0])
	{
		free(tokens);
		return (NULL);
	}
	return (tokens);
}
