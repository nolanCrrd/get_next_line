CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line.a

SRCS = \

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = \

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

AR = ar
ARFLAGS = rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
