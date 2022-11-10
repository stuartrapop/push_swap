NAME = push_swap

SRCS_PATH =./

OBJS_PATH = ./objects

SRCS_NAME = push_swap.c \
			push_swap_util.c \
			ft_printf.c \
			ft_printf_utils.c \
			commands.c \
			helpers.c \
			radix4.c \
			radix3.c \
			sort.c


SRCS = $(addprefix $(SRCS_PATH)/,$(SRCS_NAME))


HEADER_DIR = ./

FLAG = -Wall -Wextra -Werror -I$(HEADER_DIR)

CC = GCC $(FLAG)

OBJS = ${SRCS:.c=.o}

%.o:%.c
	$(CC) -o $@ -c $<

${NAME} : ${OBJS}
	make -C libft
	make bonus -C libft
	cp libft/libft.a .
	# ar rcs $(NAME) $(OBJS)
	$(CC) -L. -l ft  $(OBJS) -o${NAME}

all : ${NAME}

clean :
	rm -f ${OBJS} $(OBJS_BONUS)
	$(MAKE) -C libft clean

fclean : clean
	rm -f ${NAME}
	$(MAKE) -C libft fclean
re : fclean all

test:
	make -C libft
	cp libft/libft.a ./$(NAME)
	# ar rcs $(NAME) $(OBJS)
	$(CC)   $(OBJS) -L. -l ftprintf

.PHONY : all clean fclean re
