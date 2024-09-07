SRC = AAnimal.cpp Cat.cpp Dog.cpp Wrong.cpp Brain.cpp main.cpp
NAME = brain
OBJ = AAnimal.o Cat.o Dog.o Wrong.o Brain.o main.o
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