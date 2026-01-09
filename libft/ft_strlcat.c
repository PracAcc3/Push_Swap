/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:06:45 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/18 14:41:22 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	while (dest_len < size && dst[dest_len])
		dest_len++;
	while (src[i] && (dest_len + i + 1) < size)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	if (dest_len + i < size)
		dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	char buf[20] = "Hello";
// 	size_t len = ft_strlcat(buf, " World!", 0);
// 	printf("%s\n", buf);
// 	printf("%zu\n", len);
// 	return (0);
// }