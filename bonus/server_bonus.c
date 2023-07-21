/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:46:29 by isromero          #+#    #+#             */
/*   Updated: 2023/07/21 10:46:29 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_sig(int sig, siginfo_t *siginfo, void *unused)
{
	static t_sigdata	data;

	(void)unused;
	(void)siginfo;
	if (sig == SIGUSR1)
		data.i |= (0x01 << data.bit);
	data.bit++;
	if (data.bit == 8)
	{
		ft_printf("%c", data.i);
		data.i = 0;
		data.bit = 0;
		kill(siginfo->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf(BLUE "PID ==> "RESET "%d\n", pid);
	sa.sa_sigaction = &handle_sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause ();
	return (0);
}
