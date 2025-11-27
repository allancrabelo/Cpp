C++ = c++
C++FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC = main.cpp \
		contact.cpp \

OBJS = $(SRC:.cpp=.o)

NAME = phonebook

all: $(NAME)

$(NAME):$(OBJS)
	@$(C++) $(C++FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32m [✔]\033[0m Built $(NAME)"

%.o: %.cpp
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT:


