CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC = main.cpp parser.cpp

OBJS = $(SRC:.cpp=.o)

NAME = sed

all: $(NAME)

$(NAME):$(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32m [✔] \033[0m Built $(NAME)"

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "\033[0;31m [✗] \033[0m Cleaned object files"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m [✗] \033[0m Removed $(NAME)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
