/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:11:25 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/18 14:50:14 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int main()
// {
//     int a = 'A';
//     int b = 128;
//     printf("%d\n", ft_isascii(a));
//     printf("%d\n", ft_isascii(b));
// }