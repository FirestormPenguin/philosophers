# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivendit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 08:58:08 by mivendit          #+#    #+#              #
#    Updated: 2023/10/18 08:59:04 by mivendit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INCLUDE = ./include/philo.h
CC = gcc
CFLAGS = -Werror -Wall -Wextra -pthread -I./include # -fsanitize=thread
SRC = $(SRC_DIR)/philo.c $(SRC_DIR)/utils.c $(SRC_DIR)/init_struct.c $(SRC_DIR)/routine.c $(SRC_DIR)/actions.c $(SRC_DIR)/system_tools.c 
OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:%.c=%.o)))
OBJ_DIR = ./obj
SRC_DIR = ./src
RM = rm -rf
NORMI = norminette
NORM_FOLDER = ./src ./include

UPurple = \033[4;35m
BIRed =\033[1;91m
On_IGreen =\033[0;102m
CYAN = \033[0;36m
GREEN = \033[0;32m
RED = \033[0;31m
PURPLE = \033[1;200m
BLUE = \033[0;36m
BOLD = \033[1m
RESET = \033[0m
COLOR_SEPARATOR = \033[1;92m

SEPARATOR = "\033[1m ******************************* \033[0m"

all: obj_dir $(NAME)

$(NAME): $(OBJ)
	@echo $(SEPARATOR)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(BOLD)$(GREEN)  Compiled $(NAME) successfully$(RESET)"
	@echo "$(BOLD)$(GREEN)  READY TO START!$(RESET)"
	@echo $(SEPARATOR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

obj_dir:
	@echo "$(CYAN)  Compiling files$(PURPLE)$< $(GREEN)...$(RESET)"
	@mkdir -p $(OBJ_DIR)
	@echo "$(CYAN)  obj folder $(PURPLE)$< $(GREEN)created$(RESET)"

clean:
	@echo $(SEPARATOR)
	@$(RM) $(OBJ_DIR)
	@echo "$(BOLD)  $(UPurple)OBJ deleted$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BOLD)  $(UPurple)$(NAME) deleted$(RESET)"
	@echo $(SEPARATOR)

re: fclean all

norm:
	@echo "$(CYAN)"
	@$(NORMI) $(NORM_FOLDER)
	@echo "$(RESET)"$(SEPARATOR)

.PHONY: all clean fclean re norm obj_dir
