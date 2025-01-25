SRC = Bureaucrat.cpp main.cpp
OBJ = Bureaucrat.o main.o
NAME = bureaucrat
CPP_COMPILER = c++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 -g

all : $(NAME)

$(OBJ) : $(SRC)
	$(CPP_COMPILER) $(CPP_FLAGS) -c $(SRC)

$(NAME) : $(OBJ)
	$(CPP_COMPILER) $(OBJ) $(CPP_FLAGS) -o $(NAME)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all