CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line.a

SRCS = get_next_line.c \
	get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = get_next_line_bonus.c \
	get_next_line_utils_bonus.c \

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

AR = ar
ARFLAGS = rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -D BUFFER_SIZE=42

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BONUS_OBJS) -D BUFFER_SIZE=42

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
