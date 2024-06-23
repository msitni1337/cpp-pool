SRC=$(wildcard *.cpp)
OBJ=${SRC:.cpp=.o}

NAME=yellowbook
CFLAGS=-Wall -Werror -Wextra -std=c++98 -g3
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