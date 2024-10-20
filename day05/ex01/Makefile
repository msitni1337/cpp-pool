SRC= Bureaucrat.cpp Form.cpp main.cpp 
OBJ=${SRC:.cpp=.o}

NAME=Bureaucrat
CFLAGS=-Wall -Werror -Wextra -std=c++98 #-fsanitize=address
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