
NAME							=		containers
CC          					=    	c++
VERSION     					=    	-std=c++98
FLAGS    						=    	-Wall -Wextra -Werror
RM          					=    	rm -rf


VECTOR_TEST						=		./tests/vector/tests.cpp
MAP_TEST						=		./tests/map/tests.cpp
MAIN_FILE						=		./main.cpp	


SRC								=		./tests/vector/tests.cpp\
										./tests/map/tests.cpp\
										./tests/vector/src/capacity.cpp\
										./tests/vector/src/constructors.cpp\
										./tests/vector/src/elements.cpp\
										./tests/vector/src/iterators.cpp\
										./tests/vector/src/modifiers.cpp\
										./tests/vector/src/operators.cpp\
										./tests/map/src/capacity.cpp\
										./tests/map/src/constructors.cpp\
										./tests/map/src/iterators.cpp\
										./tests/map/src/lookup.cpp\
										./tests/map/src/modifiers.cpp\
										./tests/test_utils.cpp\
										./tests/map/src/observers.cpp

OBJ 							= 		$(SRC:.cpp=.o)


LIB								=		./includes/vector/vector.hpp\
										./includes/vector/iterator.hpp\
										./includes/vector/reverse_iterator.hpp\
										./includes/map/map.hpp\
										./includes/map/iterator.hpp\
										./includes/map/reverse_iterator.hpp\
										./includes/utils/map_utils.hpp\
										./includes/utils/utils.hpp\
										./tests/tests.hpp

all: $(NAME)


$(NAME): $(LIB) $(OBJ)
	@$(CC) $(VERSION) $(FLAGS) -o $(NAME) $(OBJ)

%.o : $(LIB) %.cpp
	$(CC) $(VERSION) $(FLAGS) -o $@ -c $<

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

re: vector map main clean fclean all
