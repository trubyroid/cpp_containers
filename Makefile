
NAME							=		containers
CC          					=    	c++
VERSION     					=    	-std=c++98
FLAGS    						=    	-Wall -Wextra -Werror
RM          					=    	rm -rf

VECTOR_TEST						=		./tests/vector/tests.cpp
MAP_TEST						=		./tests/map/tests.cpp
MAIN_FILE						=		./main.cpp	

all: $(NAME)


$(NAME):
	@$(CC) $(VERSION) $(FLAGS) $(MAIN_FILE) -o $(NAME)

vector: 
	@$(CC) $(VERSION) $(FLAGS) $(VECTOR_TEST)
	@./a.out
	@make clean

map: 
	@$(CC) $(VERSION) $(FLAGS) $(MAP_TEST)
	@./a.out
	@make clean

main:
	@$(CC) $(VERSION) $(FLAGS) $(MAIN_FILE)
	@./a.out 1
	@make clean

clean: 
	@$(RM) a.out

fclean:
	@$(RM) a.out
	@$(RM) containers

re: vector map main clean fclean all
