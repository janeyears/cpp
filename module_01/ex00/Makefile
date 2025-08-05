NAME = BraiiiiiiinnnzzzZ
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp \
		main.cpp

HEADERS = Zombie.hpp

OBJ = $(SRCS:.cpp=.o)

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