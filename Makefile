# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isromero <isromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 19:25:57 by isromero          #+#    #+#              #
#    Updated: 2023/03/23 19:39:41 by isromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk
CC			=	gcc
SRCS		=	server.c client.c
SRCS_BONUS	=	bonus/server_bonus.c bonus/client_bonus.c

LIBFT		=	libft/libft.a
PRINTF		=	ft_printf/libftprintf.a

CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)


all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C libft >/dev/null 2>&1
			@make -C ft_printf
			@make clean -C libft >/dev/null 2>&1
			@make clean -C ft_printf
			$(CC) $(OBJS) $(LIBFT) $(PRINTF) $(CFLAGS) -o $(NAME) >/dev/null 2>&1

%o:			%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS) >/dev/null 2>&1

fclean:		clean
			@$(RM) $(NAME) >/dev/null 2>&1
			@$(RM) *.out >/dev/null 2>&1
			@make fclean -C libft/ >/dev/null 2>&1
			@make fclean -C ft_printf/ >/dev/null 2>&1

re:			fclean all

.PHONY:		all clean fclean re