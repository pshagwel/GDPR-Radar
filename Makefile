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

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(H_DIR)/gdpr.h
		$(CC) $(FLAGS) -c $< -I $(H_DIR) -o $@

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $@
		chmod 775 $(NAME)
clean:
		/bin/rm -rf $(OBJ_DIR)/*.o
		
fclean: clean
		/bin/rm -f $(NAME)

makeobjdir:
		$(shell mkdir -p $(OBJ_DIR))
test:
		./gdpr gdpr.txt

re: clean makeobjdir all