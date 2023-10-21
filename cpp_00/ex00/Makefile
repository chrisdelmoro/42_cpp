NAME	= megaphone

SOURCE	= megaphone.cpp

OBJ_PATH = ./obj/
OBJ		= $(SOURCE:.cpp=.o)
OBJECTS = $(addprefix $(OBJ_PATH), $(OBJ))

BIN				= ./bin/
BINARY_OUT		= $(addprefix $(BIN), $(NAME))

COMPILE	= clang++

FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(BINARY_OUT)

$(BINARY_OUT): $(SOURCE)
	@ echo "Compiling megaphone..."
	@ $(COMPILE) $(FLAGS) -c $(SOURCE)
	@ mkdir -p obj
	@ mv $(OBJ) $(OBJ_PATH)
	@ mkdir -p $(BIN)
	@ $(COMPILE) $(FLAGS) $(OBJECTS) -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "Megaphone compiled successfully!"


clean:
	@ rm -f $(OBJECTS)
	@ rm -rf $(OBJ_PATH)
	@ echo "Object file erased successfully!"

fclean: clean
	@ rm -f $(BINARY_OUT)
	@ rm -rf $(BIN)
	@ echo "Megaphone binary erased successfully!"

re: fclean all

.PHONY: all clean fclean re