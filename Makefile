CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99 # -g

SRC=main.c instructions.c extra_instructions.c auxiliary.c
INC=monty.h

NAME=monty

all: $(NAME) $(INC)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)


clean:
	@rm -f $(NAME)

re: clean all
