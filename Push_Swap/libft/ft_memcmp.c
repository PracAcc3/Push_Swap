/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:47:11 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/18 16:11:49 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	const unsigned char	*a = s1;
	const unsigned char	*b = s2;

	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main()
// {
//     char a[] = {1, 2, 3, 4};
//     char b[] = {1, 2, 4, 4};
//     int res = ft_memcmp(a, b, 3);
//     printf("%d\n", res);
// }