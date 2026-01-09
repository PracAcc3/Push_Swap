/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:23:59 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/18 15:10:21 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *total, const char *find, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!*find)
		return ((char *)total);
	while (total[i] && i < len)
	{
		j = 0;
		while (find[j] && total[i + j] == find[j] && (i + j) < len)
		{
			j++;
		}
		if (!find[j])
			return ((char *)(total + i));
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main()
// {
// 	const char *text = ".............................this
// .............................";
// 	const char *needle = "this";
// 	char *result = ft_strnstr(text, needle, 33);
// 	printf("%s\n", result);
// }