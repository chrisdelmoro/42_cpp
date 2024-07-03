NAME			= brainz

SRC_DIR			= ./src/
SRC				=	*.cpp
SRC_PATH		= $(addprefix $(SRC_DIR), $(SRC))

OBJ_PATH 		= ./obj/
OBJ				= $(SRC:.cpp=.o)
OBJECTS 		= $(addprefix $(OBJ_PATH), $(OBJ))

BIN				= ./bin/
BINARY_OUT		= $(addprefix $(BIN), $(NAME))

COMPILE	= 		clang++
FLAGS	= 		-Wall -Wextra -Werror -std=c++98

all: $(BINARY_OUT)

$(BINARY_OUT): $(SRC_PATH)
	@ echo "Compiling brainz..."
	@ $(COMPILE) $(FLAGS) -c $(SRC_PATH)
	@ mkdir -p obj
	@ mv $(OBJ) $(OBJ_PATH)
	@ mkdir -p $(BIN)
	@ $(COMPILE) $(FLAGS) $(OBJECTS) -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "Brainz compiled successfully!"


clean:
	@ rm -f $(OBJECTS)
	@ rm -rf $(OBJ_PATH)
	@ echo "Object files erased successfully!"

fclean: clean
	@ rm -f $(BINARY_OUT)
	@ rm -rf $(BIN)
	@ echo "Brainz binary erased successfully!"

re: fclean all

.PHONY: all clean fclean re