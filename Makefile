COMPILER=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98
DFLAGS=-fsanitize=address
NAME=avl
SRC=main.cpp ./dev/helper.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(COMPILER) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(NAME)

re: clean all
