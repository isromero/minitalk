/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:52:55 by isromero          #+#    #+#             */
/*   Updated: 2023/02/08 18:10:13 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void	handle_signal(int sig)
{
	printf("not stop\n");
}

void	check_id(void)
{
	int	id = fork();
	if (id == 0)
		sleep(1);
	printf("ID actual: %d, parent ID: %d\n", getpid(), getppid());
	if (wait(NULL) == -1)
		printf("no children to wait pequeño\n");
}

int	main(int argc, char **argv)
{
	struct sigaction sa;
	sa.sa_handler = &handle_signal;
	sa.sa_flags = SA_RESTART; //No necesito manejar nada
	sigaction(SIGTSTP, &sa, NULL);

	//signal(SIGTSTP, &handle_signal); //la manera corta de hacer lo mismo que arriba
	
	//pero es mas conveniente lo otro para cualquier version de unix
	
	int	x;
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	check_id();
	return 0;
}

