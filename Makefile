.PHONY: all clean fclean re

CC          					=    	c++
VERSION     					=    	-std=c++98
#CPPFLAGS    					=    	-Wall -Wextra -Werror -g
NAME        					=		containers
RM          					=    	rm -rf

SRC_PATH						=		./srcs
OBJ_PATH						=		./objs

MAIN							=		./main.cpp
SRC								=		

OBJ_NAME						=		$(SRC:.cpp=.o)

OBJ								=		$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(VERSION) $(CPPFLAGS) -o $(NAME) $(OBJ)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		$(CC) $(VERSION) -o $@ -c $<

clean: 
	@$(RM) $(OBJ_PATH)

fclean:          clean
	@$(RM) $(NAME)

re: fclean all