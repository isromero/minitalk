/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:21:22 by isromero          #+#    #+#             */
/*   Updated: 2023/07/21 09:21:22 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void    handle_confirmation(int sig, siginfo_t *siginfo, void *unused)
{
	(void)siginfo;
	(void)unused;
    static t_sigdata data;
    if (sig == SIGUSR2 && !data.boolean)
    {
		ft_printf(GREEN "Message received\n" RESET);
        data.boolean = true;
    }
}

void	send_message(pid_t pid, char i)
{
	int	bit;
	
	bit = 0;
	while (bit < 8) //Un carácter tiene 8 bits que conforman un byte
	{
		if ((i & (0x01 << bit)) != 0) //Comprobación del estado bit a bit y se manda con kill
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		byte;
	struct sigaction sa;

	byte = 0;
	if (argc == 3)
	{
		sa.sa_sigaction = &handle_confirmation;
		sa.sa_flags = SA_SIGINFO;
		pid = atoi(argv[1]);
		while(argv[2][byte] != '\0')
		{
			sigaction(SIGUSR2, &sa, NULL);
			send_message(pid, argv[2][byte]);
			byte++;
		}
		send_message(pid, '\n');
	}
	else
	{
		ft_printf(RED "Error: wrong format.\n" RESET);
        ft_printf(YELLOW "Usage: %s <PID> <MESSAGE>\n" RESET, argv[0]);
	}
	return (0);
}
