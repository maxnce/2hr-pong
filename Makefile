##	WeekEnd chall n1
##	c++ SFML Pong

CFLAGS = -Wall -Wextra -Wpedantic -g3 -I./include

LM = -lm

NCURSES = -lncurses

CSFML = -l csfml-graphics -l csfml-window -l csfml-system -l csfml-network -l csfml-audio
SFML = -l sfml-graphics -l sfml-window -l sfml-system -l sfml-network -l sfml-audio -lfreetype -DSFML_STATIC

SRC	=	source/main.cpp \

OBJ 	=	$(SRC:.cpp=.o) $(MAIN:.cpp=.o)

NAME	=	pong

all:	$(NAME)

$(NAME):	$(OBJ)
		@g++ -o $(NAME) $(SRC) $(CFLAGS) $(SFML)
		@rm -f *.o source/*.o library/*.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	 all re clean fclean