/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:10:50 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/15 15:16:49 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int digit)
{
	if (digit >= '0' && digit <= '9')
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int main()
// {
//     int a = 'a';
//     int b = '3';
//     printf("%d\n", ft_isdigit(a));
//     printf("%d\n", ft_isdigit(b));
// }