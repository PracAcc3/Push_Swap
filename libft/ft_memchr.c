/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:21:25 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/18 16:41:47 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str = s;
	unsigned char		t;
	size_t				i;

	i = 0;
	t = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == t)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
//     char s[] = "This char";
//     char *a = ft_memchr(s, 'c', 10);
//     printf("%c\n", *a);
// 	char *b = ft_memchr(s, 'c', 1);
// 	printf("%c\n", *b);
// }