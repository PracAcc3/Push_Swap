/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:56:34 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/18 16:36:25 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	unsigned int	i;
	char			*dup;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

// #include <stdio.h>

// int main()
// {
//     const char *org = "This";
//     char *copy = ft_strdup(org);
//     printf("Orginal: %s\n", org);
//     printf("Copy: %s\n", copy);
//     free(copy);
// }