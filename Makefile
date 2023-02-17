# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 21:52:57 by marvin            #+#    #+#              #
#    Updated: 2023/02/14 21:52:57 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(CLIENT) $(SERVER)
	
$(CLIENT):
	cd libft && make all
	cd printf && make all
	cc $(FLAGS) libft/libft.a printf/libftprintf.a client.c -o $(CLIENT)
$(SERVER):
	cd libft && make all
	cd printf && make all
	cc $(FLAGS) libft/libft.a printf/libftprintf.a server.c -o $(SERVER)

clean:
	cd libft && make clean
	cd printf && make clean
	cc $(FLAGS) libft/libft.a printf/libftprintf.a client.c -o $(CLIENT)
	cc $(FLAGS) libft/libft.a printf/libftprintf.a server.c -o $(SERVER)
	
fclean:
	cd libft && make fclean
	cd printf && make fclean
	$(RM) client
	$(RM) server


re:
	cd libft && make re
	cd printf && make re
	cc $(FLAGS) libft/libft.a printf/libftprintf.a client.c -o $(CLIENT)
	cc $(FLAGS) libft/libft.a printf/libftprintf.a server.c -o $(SERVER)

.PHONY: all clean fclean re