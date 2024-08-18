SRC = Contact.cpp PhoneBook.cpp main.cpp
NAME = phone_book
OBJ = Contact.o PhoneBook.o main.o
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -g
CPP_COMPILER = c++ 

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP_COMPILER) $(OBJ) $(CPP_FLAGS) -o $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
