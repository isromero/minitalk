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


struct sig_data data;
void    handle_sig(int sig, siginfo_t *siginfo, void *unused)
{
    pid_t   pid;
    struct sigaction sa;

    pid = getpid();
    if (sig == SIGUSR1)
    {
        data.i |= (0x01 << data.bit);
    } //Desplazamos el bit 1 a la izquierda si es SIGUSR1
    data.bit++;
    if (data.bit == 8)
    {
        printf("%c", data.i);
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
    printf("PID: %d\n", pid);
    sa.sa_sigaction = &handle_sig;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    while(1)
    {
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
    }
 
    return (0);
}