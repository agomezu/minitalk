/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:04:06 by agomez-u          #+#    #+#             */
/*   Updated: 2023/07/28 15:04:07 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(1500);
}

void	send_character(int pid, char character)
{
	int	bit;
	int	i;

	i = -1;
	while (++i < 8)
	{
		bit = (character >> i) & 1;
		send_bit(pid, bit);
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = -1;
	while (message[++i])
		send_character(pid, message[i]);
	send_character(pid, '\0');
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		write(2, "Usage: ./client <PID> <message>\n", 32);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}
