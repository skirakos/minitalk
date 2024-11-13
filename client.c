/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:50:38 by skirakos          #+#    #+#             */
/*   Updated: 2024/06/16 18:58:09 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	g_received = 0;

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		if (g_received == 0)
			ft_printf("The message has been received!\n");
		g_received = 1;
	}
}

void	message_to_bits(int pid, char *message)
{
	int		shift;
	size_t	i;

	i = 0;
	while (message[i])
	{
		shift = 0;
		while (shift < 8)
		{
			if ((message[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(300);
		}
		i++;
		while (!g_received)
			pause();
		g_received = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Argument error\n");
		exit(1);
	}
	signal(SIGUSR1, &handler);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	message_to_bits(pid, message);
	message_to_bits(pid, "\n");
	return (0);
}
