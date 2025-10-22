NAME = a.out

CC = cc
CFLAGS = -I ./lib/ -I . -lreadline

DIR_OBJ = build
DIR_LIB = lib

SRCS = $(wildcard *.c) $(wildcard $(DIR_LIB)/*.c)
OBJS = $(SRCS:%.c=$(DIR_OBJ)/%.o)

$(NAME): $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

$(DIR_OBJ)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -rf $(NAME)

all: $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean all re
