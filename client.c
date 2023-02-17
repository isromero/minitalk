/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:52:55 by isromero          #+#    #+#             */
/*   Updated: 2023/02/14 22:34:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "printf/ft_printf.h"

void	send_message(pid_t pid, char i)
{
	int	bit;
	
	bit = 0;
	while (bit < 8) //Un carácter tiene 8 bits que conforman un byte
	{
		if ((i & (0x01 << bit)) != 0) //Comprobación del estado bit a bit y se manda con kill
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

	pid = atoi(argv[1]);
	byte = 0;
	if (argc == 3)
	{
		
		while(argv[2][byte] != '\0')
		{
			send_message(pid, argv[2][byte]);
			byte++;
		}
		send_message(pid, '\n');
	}
	else
		ft_printf("error\n");

	return (0);
}
