.PHONY: all clean fclean re

CC          					=    	c++
VERSION     					=    	-std=c++98
CPPFLAGS    					=    	-Wall -Wextra -Werror
RM          					=    	rm -rf

SRC_PATH						=		./srcs
VECTOR_TEST						=		./tests/vector/tests.cpp
MAP_TEST						=		./tests/map/tests.cpp
MAIN_FILE						=		./main.cpp	


all: vector map main

vector: 
	@$(CC)	$(VECTOR_TEST)
	@./a.out
	@make clean

map: 
	@$(CC)	$(MAP_TEST)
	@./a.out
	@make clean

main:
	@$(CC) $(VERSION) $(CPPFLAGS) $(MAIN_FILE)
	@./a.out 1
	@make clean

clean: 
	@$(RM) a.out

fclean:
	@$(RM) a.out

re: vector map main clean fclean all