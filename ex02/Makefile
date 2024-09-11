NAME = special_forms

CC = c++
FLAGS = -Wall -Wextra -Werror --std=c++98
DEBUG_FLAGS = -g3

SRC_DIR = src/
SRC_FILES = $(addprefix $(SRC_DIR), \
			main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp)

OBJ_DIR = obj/
OBJ_FILES = $(addprefix $(OBJ_DIR), $(notdir $(SRC_FILES:.cpp=.o)))

INC_DIR = src/include

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "Linking objects and generating executable \033[32m$(NAME)\033[0m"
	@$(CC) $(FLAGS) -I $(INC_DIR) $(SRC_FILES) -o $(NAME)
	@echo "Done."

#pattern rule for object files
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling object" $(notdir $@)
	@$(CC) $(FLAGS) -I $(INC_DIR) -c $< -o $@
	@echo Done.

clean:
	@echo "Removing object files and directory..."
	@rm -rf $(OBJ_DIR)
	@echo "Done."

fclean: clean
	@echo "Removing executable..."
	@rm -f $(NAME)
	@echo "Done."

re: fclean all

debug: fclean
	@$(CC) $(FLAGS) $(DEBUG_FLAGS) -I $(INC_DIR) $(SRC_FILES) -o $(NAME)
	gdb ./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)

.PHONY : all clean fclean re
