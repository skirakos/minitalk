/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:21:09 by skirakos          #+#    #+#             */
/*   Updated: 2024/02/19 18:21:13 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print(char c, int fd)
{
	write(fd, &c, 1);
}

void	putnbr(int nb, int fd)
{
	if (nb == -2147483648)
	{
		print('-', fd);
		print('2', fd);
		putnbr(147483648, fd);
	}
	else if (nb < 0)
	{
		print('-', fd);
		nb = -nb;
		putnbr(nb, fd);
	}
	else if (nb > 9)
	{
		putnbr(nb / 10, fd);
		putnbr(nb % 10, fd);
	}
	else
		print(nb + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	putnbr(n, fd);
}

// int main()
// {
// 	ft_putnbr_fd(5, 1);
// }
