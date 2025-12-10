/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:44:02 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/18 16:38:20 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// #include <stdio.h>

// char	toupper_test(unsigned int i, char c)
// {
// 	(void)i;
// 	return (ft_toupper((int)c));
// }
// int	main()
// {
// 	char *result = ft_strmapi("uppercase hgf hbb", toupper_test);
// 	printf("%s\n", result);
// 	free(result);
// }