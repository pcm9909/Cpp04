NAME = Animal
CC = clang++
FLAG =  -std=c++98 -g
SRCS = Animal.cpp Cat.cpp Dog.cpp Brain.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAG) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(FLAG) -c $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
