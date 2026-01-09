/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:11:15 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/18 14:49:38 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int main()
// {
//     int a = 'a';
//     int b = '3';
//     int c = '*';
//     printf("%d\n", ft_isalnum(a));
//     printf("%d\n", ft_isalnum(b));
//     printf("%d\n", ft_isalnum(c));
// }
