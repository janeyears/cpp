NAME = btc

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

SRCS = main.cpp \
		BitcoinExchange.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
