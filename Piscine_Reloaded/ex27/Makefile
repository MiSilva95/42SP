NAME = ft_display_file

SRCS = ./ft_display_file.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	cc -o ${NAME} ${OBJS} ${FLAGS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean