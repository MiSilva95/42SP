NAME = fractol

SRC_DIR = src
INC_DIR = includes

SRC = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/render.c \
	$(SRC_DIR)/events.c \
	$(SRC_DIR)/math_utils.c \
	$(SRC_DIR)/string_utils.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

MLX_FLAGS = -lmlx -lXext -lX11 -lm

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)
	@echo "[✓] $(NAME) compiled!"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "[✓] Objects cleaned!"

fclean: clean
	@rm -f $(NAME)
	@echo "[✓] Full clean done!"

re: fclean all

.PHONY: all clean fclean re
