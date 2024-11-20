SRC= PmergeMe.cpp main.cpp
OBJ=${SRC:.cpp=.o}

NAME=PmergeMe
CFLAGS=-Wall -Werror -Wextra -std=c++98 #-g3 -fsanitize=address
CXX=c++

.SECONDARY: ${OBJ}
.PHONY: all clean fclean re

%.o: %.cpp
	${CXX} ${CFLAGS} $< -c -o $@ 

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all