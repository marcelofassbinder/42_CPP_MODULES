SRC = Animal.cpp Cat.cpp Dog.cpp Wrong.cpp main.cpp
NAME = animal
OBJ = Animal.o Cat.o Dog.o Wrong.o main.o
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -g 
CPP_COMPILER = c++ 

all: $(NAME)

$(OBJ): $(SRC)
	$(CPP_COMPILER) $(CPP_FLAGS) -c $(SRC)

$(NAME): $(OBJ)
	$(CPP_COMPILER) $(OBJ) $(CPP_FLAGS) -o $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all