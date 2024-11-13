/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:55:49 by skirakos          #+#    #+#             */
/*   Updated: 2024/06/16 18:55:50 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	static int				current_bit_position = 0;
	static unsigned char	current_char = 0;

	if (sig == SIGUSR2)
		current_char |= (1 << current_bit_position);
	current_bit_position++;
	if (current_bit_position == 8)
	{
		write(STDOUT_FILENO, &current_char, 1);
		current_char = 0;
		current_bit_position = 0;
		kill(siginfo->si_pid, SIGUSR1);
	}
	(void)context;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	printf("Process ID: %d\n", getpid());
	while (1)
		pause();
	(void)argc;
	(void)argv;
	return (0);
}
