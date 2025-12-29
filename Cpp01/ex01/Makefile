CPP       := c++
CPPFLAGS  := -Wall -Wextra -Werror -std=c++98 -pedantic

NAME      := MoarBrainz

SRC_DIR   := .
OBJ_DIR   := obj

SRC_FILES := main.cpp \
             Zombie.cpp \
             zombieHorde.cpp

OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CPP) $(CPPFLAGS) $^ -o $@
	@echo "\033[0;32m[✔]\033[0m Built $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[0;31m[✗]\033[0m Cleaned object files"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m[✗]\033[0m Removed $(NAME)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
