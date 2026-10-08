C++ = c++
C++FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Base.cpp

OBJS = $(SRC:.cpp=.o)

NAME = identifier

all: $(NAME)

$(NAME):$(OBJS)
	@$(C++) $(C++FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
