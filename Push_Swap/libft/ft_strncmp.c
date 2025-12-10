/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:36:04 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/17 17:08:09 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	len;

	len = 0;
	while (len < n && s1[len] && s1[len] == s2[len])
		len++;
	if (len == n)
		return (0);
	return ((unsigned char)s1[len] - (unsigned char)s2[len]);
}

// #include <stdio.h>

// int main()
// {
//     printf("%d\n", ft_strncmp("thau", "that", 3));
//     printf("%d\n", ft_strncmp("thbu", "that", 3));
//     printf("%d\n", ft_strncmp("thau", "thbt", 3));
// }