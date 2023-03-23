/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:39:23 by marvin            #+#    #+#             */
/*   Updated: 2023/02/14 23:39:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <stdbool.h>

t_sigdata data; //La razón es que cada vez que se reciba una señal, se crearía una nueva instancia de la variable data, y se perdería la información almacenada en la llamada anterior de la función.

void    init(t_sigdata data)
{
    data.i = 0;
    data.bit = 0;
}

void    handle_sig(int sig, siginfo_t *siginfo, void *unused)
{
    pid_t   pid;
    struct sigaction sa;
    

    pid = getpid();
    if (sig == SIGUSR1)
        data.i |= (0x01 << data.bit); //Desplazamos el bit 1 a la izquierda si es SIGUSR1
    data.bit++;
    if (data.bit == 8)
    {
        ft_printf("%c", data.i);
        data.i = 0;
        data.bit = 0;
        kill(siginfo->si_pid, SIGUSR2);
    }
}

int main(int argc, char **argv) 
{
    struct sigaction sa;
    pid_t   pid;

    (void)argv;
    pid = getpid();
    ft_printf("PID: %d\n", pid);
    sa.sa_sigaction = &handle_sig; //para conseguir mas informacion de la señal
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    while(1)
    {
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
    }
 
    return (0);
}