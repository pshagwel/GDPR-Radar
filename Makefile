NAME = gdpr

H_DIR = includes
SRC_DIR = srcs
OBJ_DIR = obj

SRC =	gnl.c \
		gnl_utils.c \
		main.c \
		ft_itoa.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
CC = gcc
FLAGS = -Wall -Wextra -Werror
FLAGS += -ggdb3

.PHONY: all clean fclean re app

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
		/bin/rm -rf app
		/bin/rm -f conclusion.txt

makeobjdir:
		$(shell mkdir -p $(OBJ_DIR))
app: $(NAME)
		$(shell mkdir -p "app")
		$(shell mv gdpr app/gdpr)
		$(shell cp phrases.txt app/phrases.txt)
		$(shell cp doc.txt app/doc.txt)

re: clean makeobjdir all