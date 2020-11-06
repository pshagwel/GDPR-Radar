NAME = gdpr

H_DIR = includes
SRC_DIR = srcs
OBJ_DIR = obj

SRC =	gnl.c \
		gnl_utils.c \
		main.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
CC = gcc
FLAGS = -Wall -Wextra -Werror
FLAGS += -ggdb3

.PHONY: all clean fclean re bonus

$(shell mkdir -p $(OBJ_DIR))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c gdpr.h
		$(CC) $(FLAGS) -c $< -I $(H_DIR) -o $@

$(NAME): $(OBJ)
		$(CC) $(FLAGS) -c $(OBJ) -I $(H_DIR) -o $@
clean:
		/bin/rm -rf $(OBJ_DIR)/*.o
		
fclean: clean
		/bin/rm -f $(NAME)

makeobjdir:
		$(shell mkdir -p $(OBJ_DIR))

re: clean makeobjdir all