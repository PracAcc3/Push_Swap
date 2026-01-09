/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:44:53 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/18 14:48:54 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = malloc(num * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num * size);
	return (ptr);
}

// #include <stdio.h>

// int	main()
// {
// 	int *a = ft_calloc(10, sizeof(int));
// 	if (!a)
// 		return (1);
// 	int i = 0;
// 	while (i < 10) 
// 		printf("%d ", a[i++]);
// //		0 0 0 0 0 0 0 0 0 0 
// 	printf("\n");
// 	free(a);
// }