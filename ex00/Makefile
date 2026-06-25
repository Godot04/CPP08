NAME	:= ex00
SRC		:= main.cpp
OBJDIR	:= obj
OBJ		:= $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))

CC++	:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC++) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(OBJDIR)
	$(CC++) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
