/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:23:43 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/18 15:54:51 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*i;

	i = 0;
	while (*s)
	{
		if (*s == (char)c)
			i = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)i);
}

// #include <stdio.h>

// int main()
// {
//     const char *text = "a find a";
//     printf("Found: %s\n", ft_strrchr(text, 'a'));
// }