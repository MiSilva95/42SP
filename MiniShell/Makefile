NAME        = minishell
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
INC_DIR     = INCLUDES
INCLUDES    = -I$(INC_DIR) -I$(LIBFT_DIR)

SRC         = main.c tokenizer.c external_comms.c BTIN_pwd.c BTIN_cd.c BTIN_env.c BTIN_export.c BTIN_system_variables.c BTIN_unset.c BTIN_echo.c BTIN_exit.c minishell_utils.c tokenizer_op.c REDIR_functions.c REDIR_heredoc.c REDIR_utils.c SIGNAL_functions.c pipe_parser.c pipe_exec.c
OBJ_DIR     = obj
OBJ         = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror $(INCLUDES) -g
RLFLAGS     = -lreadline

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(RLFLAGS) -o $(NAME)
	@echo "[✓] $(NAME) compiled!"

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)
	@echo "[✓] libft compiled!"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@echo "[✓] Objects cleaned!"

fclean: clean
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "[✓] Full clean done!"

re: fclean all

.PHONY: all clean fclean re

