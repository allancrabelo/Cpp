C++ = c++
C++FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJS = $(SRC:.cpp=.o)

NAME = BraiiiiiiinnnzzzZ

all: $(NAME)

$(NAME):$(OBJS)
	@$(C++) $(C++FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32m [✔] \033[0m Built $(NAME)"

%.o: %.cpp
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "\033[0;31m [✗] \033[0m Cleaned object files"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m [✗] \033[0m Removed $(NAME)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
