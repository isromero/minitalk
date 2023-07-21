/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:25:38 by isromero          #+#    #+#             */
/*   Updated: 2023/07/21 09:44:43 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H


#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

#define RED "\e[0;31m"
#define YELLOW "\033[1;93m"
#define BLUE "\e[0;34m"
#define RESET "\033[0m"

typedef struct sig_data
{
    int i;
    int bit;
} t_sigdata;

#endif