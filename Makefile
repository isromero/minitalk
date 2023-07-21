# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 19:25:57 by isromero          #+#    #+#              #
#    Updated: 2023/07/21 09:28:18 by isromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = all
CC = gcc
CFLAGS = -Wall -Wextra #-Werror

LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf

SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_DIR = obj
OBJ_CLIENT = $(addprefix $(OBJ_DIR)/,$(SRC_CLIENT:.c=.o))
OBJ_SERVER = $(addprefix $(OBJ_DIR)/,$(SRC_SERVER:.c=.o))

SRC_CLIENT_BONUS = bonus/client_bonus.c
SRC_SERVER_BONUS = bonus/server_bonus.c

OBJ_DIR_BONUS = obj_bonus
OBJ_CLIENT_BONUS = $(addprefix $(OBJ_DIR_BONUS)/,$(notdir $(SRC_CLIENT_BONUS:.c=.o)))
OBJ_SERVER_BONUS = $(addprefix $(OBJ_DIR_BONUS)/,$(notdir $(SRC_SERVER_BONUS:.c=.o)))

PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

all: $(OBJ_DIR) client server

client: $(OBJ_CLIENT)
	@make -C $(FT_PRINTF_DIR) >/dev/null 2>&1
	@make -C $(LIBFT_DIR) >/dev/null 2>&1
	$(CC) $(CFLAGS) $^ $(LIBFT) $(PRINTF) -o $@

server: $(OBJ_SERVER)
	$(CC) $(CFLAGS) $^ $(LIBFT) $(PRINTF) -o $@

$(OBJ_DIR)/%.o: %.c
	@tput setaf 6; echo "Compiling $<..."; tput sgr0
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

bonus: $(OBJ_DIR_BONUS) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
	@make -C $(FT_PRINTF_DIR) >/dev/null 2>&1
	@make -C $(LIBFT_DIR) >/dev/null 2>&1
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(LIBFT) $(PRINTF) -o bonus/client_bonus
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(LIBFT) $(PRINTF) -o bonus/server_bonus
	@tput setaf 2; echo "Bonus compilation completed successfully!"; tput sgr0

$(OBJ_DIR_BONUS)/%.o: bonus/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS):
	mkdir -p $(OBJ_DIR_BONUS)

clean:
	@make clean -C $(FT_PRINTF_DIR) >/dev/null 2>&1
	@make clean -C $(LIBFT_DIR) >/dev/null 2>&1
	$(RM) -r $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@tput setaf 3; echo "Object files cleaned."; tput sgr0

fclean: clean
	@make fclean -C $(FT_PRINTF_DIR) >/dev/null 2>&1
	@make fclean -C $(LIBFT_DIR) >/dev/null 2>&1
	$(RM) client server bonus/server_bonus bonus/client_bonus
	@tput setaf 3; echo "Executable files cleaned."; tput sgr0

re: fclean all