/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:46:58 by isromero          #+#    #+#             */
/*   Updated: 2023/07/21 10:46:58 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# define RED "\e[0;31m"
# define YELLOW "\033[1;93m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define RESET "\033[0m"

typedef struct sig_data
{
	int		i;
	int		bit;
	bool	boolean;
}	t_sigdata;

#endif