SRC = src/AMateria.cpp src/Character.cpp src/Ice.cpp src/Cure.cpp src/Floor.cpp src/main.cpp 
NAME = materia
OBJ = AMateria.o Character.o Ice.o Cure.o Floor.o main.o
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