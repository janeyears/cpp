NAME =  MoarBrainz!
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Zombie.cpp \
		zombieHorde.cpp \
		main.cpp
OBJ = $(SRCS:.cpp=.o)

HEADERS = Zombie.hpp

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re