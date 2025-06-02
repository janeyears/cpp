NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Phonebook.cpp \
		Contact.cpp \
		main.cpp
OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re