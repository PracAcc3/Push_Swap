/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:11:41 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/18 14:50:45 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int main()
// {
//     int a = 'A';
//     int b = '\n';
//     printf("%d\n", ft_isprint(a));
//     printf("%d\n", ft_isprint(b));
// }