/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:24:58 by isromero          #+#    #+#             */
/*   Updated: 2023/07/21 11:46:09 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(pid_t pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		if ((i & (0x01 << bit)) == 0)
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		byte;

	byte = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][byte] != '\0')
		{
			send_message(pid, argv[2][byte]);
			byte++;
		}
		send_message(pid, '\n');
	}
	else
	{
		ft_printf(RED "Error: wrong format.\n" RESET);
		ft_printf(YELLOW "Usage: %s <PID> <MESSAGE>\n" RESET, argv[0]);
		return (1);
	}
	return (0);
}
