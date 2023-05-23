CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99

SRC=main.c instructions.c auxiliary.c
INC=monty.h

NAME=monty

all: $(NAME) $(INC)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)


clean:
	@rm -f $(NAME)

re: clean all
