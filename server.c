/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:04:11 by agomez-u          #+#    #+#             */
/*   Updated: 2023/07/28 15:06:04 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_bit(int sig)
{
	static char	character = 0;
	static int	bits_received = 0;

	character |= ((sig == SIGUSR2) << bits_received);
	bits_received++;
	if (bits_received == 8)
	{
		if (character == '\0')
			write(1, "\n", 1);
		else
			write(1, &character, 1);
		character = 0;
		bits_received = 0;
	}
}

void	init_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_bit;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit (1);
	}
}

int	main(void)
{
	printf("Server running with PID: %d\n", getpid());
	init_signals();
	while (1)
		pause();
	return (0);
}
