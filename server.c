/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:36:21 by marvin            #+#    #+#             */
/*   Updated: 2023/02/09 21:36:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


struct sig_data data;

void    handle_sig(int sig)
{
    if (sig == SIGUSR1)
        data.i |= (0x01 << data.bit); //Desplazamos el bit 1 a la izquierda si es SIGUSR1
    data.bit++;
    if (data.bit == 8)
    {
        ft_printf("%c", data.i);
        data.i = 0;
        data.bit = 0;
    }
}

int main(int argc, char **argv) 
{
    struct sigaction sa;
    sa.sa_handler = &handle_sig;
    pid_t   pid;
    (void)argv;
    pid = getpid();
    ft_printf("PID: %d\n", pid);
    if (argc)
    {
        while(1)
        {
            sigaction(SIGUSR1, &sa, NULL);
            sigaction(SIGUSR2, &sa, NULL);
        }
    }
    return (0);
}