/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:13:03 by isromero          #+#    #+#             */
/*   Updated: 2023/07/21 09:13:03 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sig(int sig)
{
	static t_sigdata	data;

	if (sig == SIGUSR1)
		data.i |= (0x01 << data.bit);
	data.bit++;
	if (data.bit == 8)
	{
		ft_printf("%c", data.i);
		data.i = 0;
		data.bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf(BLUE "PID ==> "RESET "%d\n", pid);
	sa.sa_handler = &handle_sig;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause ();
	return (0);
}
