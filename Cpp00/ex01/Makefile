CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
VALGRINDFLAGS = --leak-check=full --track-origins=yes --show-leak-kinds=all

NAME = phonebook

SRC = main.cpp \
		contact.cpp \
		phonebook.cpp \
		contact_adder.cpp \
		search.cpp

OBJ_DIR = .obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m[✔] Built $(NAME)\033[0m"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

valgrind: $(NAME)
	@valgrind $(VALGRINDFLAGS) ./$(NAME)

credit:
	@echo " =================================================="
	@echo "     PhoneBook - C++ Project (CPP00)
	@echo " =================================================="
	@echo " Developer: Allan Rabelo - Fullstack Developer"
	@echo " Institution: 42 School® Porto - 2025"
	@echo " ------------------------------------------"
	@echo " Email: allanaugustocarneirorabelo@gmail.com"
	@echo " GitHub: https://github.com/allancrabelo"
	@echo " ------------------------------------------"
	@echo " Total Commits: $(shell git rev-list --count HEAD 2>/dev/null || echo 'N/A')"
	@echo " Last Updated: $(shell git log -1 --format=%cd --date=short 2>/dev/null || echo 'N/A')"
	@echo " ================================================="

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[0;33m[!] Cleaned object files\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m[✖] Removed $(NAME)\033[0m"

re: fclean all

.PHONY: all clean fclean re credit valgrind
