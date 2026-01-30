/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yazi <mel-yazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:22:08 by mel-yazi          #+#    #+#             */
/*   Updated: 2025/12/30 09:16:38 by mel-yazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	temp;

	temp = n;
	if (temp < 0)
	{
		temp = -temp;
		write(fd, "-", 1);
	}
	if (temp > 9)
		ft_putnbr_fd(temp / 10, fd);
	ft_putchar_fd((temp % 10 + '0'), fd);
}
