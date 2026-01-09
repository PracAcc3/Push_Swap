/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:30:49 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/08 15:30:49 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *input, char delimiter)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*input)
	{
		inside_word = false;
		while (*input == delimiter)
			++input;
		while (*input != delimiter && *input)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++input;
		}
	}
	return (count);
}

static char	*get_next_word(char *input, char delimiter, int *cursor)
{
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (input[*cursor] == delimiter)
		++(*cursor);
	while ((input[*cursor + len] != delimiter) && input[*cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((input[*cursor] != delimiter) && input[*cursor])
		next_word[i++] = input[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *input, char delimiter)
{
	int		words_count;
	char	**tokens;
	int		i;
	int		cursor;
	int		j;

	i = 0;
	cursor = 0;
	words_count = count_words(input, delimiter);
	if (!words_count)
		return (NULL);
	tokens = malloc(sizeof(char *) * (size_t)(words_count + 1));
	if (!tokens)
		return (NULL);
	while (i < words_count)
	{
		tokens[i] = get_next_word(input, delimiter, &cursor);
		if (!tokens[i])
		{
			j = 0;
			while (j < i)
				free(tokens[j++]);
			free(tokens);
			return (NULL);
		}
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}