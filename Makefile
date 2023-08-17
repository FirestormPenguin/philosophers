NAME = philo
INCLUDE = ./include/philo.h
CC = gcc
CFLAGS = -Werror -Wall -Wextra -g -I./include
SRC = .$(SRC_DIR)/philo.c
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
OBJ_DIR = ./obj
SRC_DIR = ./src
RM = rm -rf
NORMI = norminette
NORM_FOLDER = ./src ./include

all: obj_dir $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

obj_dir:
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	$(NORMI) $(NORM_FOLDER)

.PHONY: all clean fclean re norm obj_dir
