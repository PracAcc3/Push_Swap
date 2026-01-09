/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:08:31 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/15 15:16:52 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int alpha)
{
	if ((alpha >= 'A' && alpha <= 'Z') || (alpha >= 'a' && alpha <= 'z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int main()
// {
//     int a = 'a';
//     int b = '3';
//     printf("%d\n", ft_isalpha(a));
//     printf("%d\n", ft_isalpha(b));
// }
