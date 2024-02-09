NAME = libftprintf.a
SRCS = ft_print_hex.c ft_printf.c ft_print_ptr.c ft_print_unsigned.c ft_print_utils.c
INCLUDE = include
LIBFT = libft
SRC_DIR = src/
OBJ_DIR = obj/

OBJ = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	make -C $(LIBFT)
	${CC} ${CFLAGS} ${OBJ} -o ${NAME} ${INCLUDE}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

bonus: $(BONUS_OBJ) $(OBJ)
	ar rc $(NAME) $(BONUS_OBJ) $(OBJ)

.PHONY: all clean fclean re bonus
