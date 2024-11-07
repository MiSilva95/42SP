# Nome da biblioteca
NAME = libft.a

# Diretórios
SRCS_DIR = srcs
INCS_DIR = includes

# Lista de arquivos fonte
SRCS = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c

# Gera a lista de arquivos objeto a partir da lista de fontes
OBJS = $(SRCS:%.c=%.o)

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCS_DIR)

# Regras principais
all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $@ $^

# Regras de limpeza
clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

# Regra para compilar os arquivos objeto
%.o: $(SRCS_DIR)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

