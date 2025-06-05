NAME = minitalk

SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

HEADER = src
LIBFT = ft_printf

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(HEADER) -I$(LIBFT)/include -g

all: client server

client: $(OBJ_CLIENT)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) -o client $(LIBFT)/libftprintf.a
	@echo "[✓] Client compiled!"

server: $(OBJ_SERVER)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) -o server $(LIBFT)/libftprintf.a
	@echo "[✓] Server compiled!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "[✓] Compiling $@"

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	@make -C $(LIBFT) clean
	@echo "[✓] Objects cleaned!"

fclean: clean
	rm -f client server
	@make -C $(LIBFT) fclean
	@echo "[✓] Full clean done!"

re: fclean all

.PHONY: all clean fclean re client server