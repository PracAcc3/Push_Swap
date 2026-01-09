/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:59:34 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/18 16:37:59 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			count++;
			s += word_len(s, c);
		}
	}
	return (count);
}

int	fill_words(char **out, const char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = word_len(s, c);
			out[i] = ft_substr(s, 0, len);
			if (!out[i])
				return (0);
			s += len;
			i++;
		}
	}
	out[i] = NULL;
	return (1);
}

void	free_all(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**out;

	if (!s)
		return (NULL);
	out = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	if (!fill_words(out, s, c))
	{
		free_all(out);
		return (NULL);
	}
	return (out);
}

// #include <stdio.h>

// int	main()
// {
// 	char **s = ft_split("Cut . . .", ' ');

// 	printf("0: %s\n", s[0]);
// 	free(s[0]);
// 	printf("1: %s\n", s[1]);
// 	free(s[1]);
// 	printf("2: %s\n", s[2]);
// 	free(s[2]);
// 	free(s);
// }
