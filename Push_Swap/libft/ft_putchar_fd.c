/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:03:03 by synoshah          #+#    #+#             */
/*   Updated: 2025/07/18 16:38:44 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main()
// {
// 	ft_putchar_fd('H', 1);
// 	ft_putchar_fd('I', 1);
// 	ft_putchar_fd('\n', 1);
// 	return (0);
// }