LIB_DIR = .libs
OBJ_DIR = .objs
SRC_DIR = requirements/functions

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

MAIN_SRC = requirements/main.cpp
MAIN_OBJ = $(OBJ_DIR)/main.o

CC = g++
CPPFLAGS = -Wall -Wextra -Werror -MMD -MP -gdwarf-2

DIRDUP = mkdir -p $(@D)

NAME = Nibbler
SDL_LIB = $(LIB_DIR)/libSDL.so

all: $(NAME) $(SDL_LIB)

$(NAME): $(OBJS) $(MAIN_OBJ)
	@printf "\033[0;32mCompilation successful.\033[0m\n"
	@$(CC) $(OBJS) $(MAIN_OBJ) -lSDL2 -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@$(DIRDUP)
	@$(CC) $(CPPFLAGS) -c -o $@ $<

$(MAIN_OBJ): $(MAIN_SRC)
	@$(DIRDUP)
	@$(CC) $(CPPFLAGS) -c -o $@ $<

$(OBJ_DIR)/SDL.o: $(SRC_DIR)/SDL.cpp
	@$(DIRDUP)
	@$(CC) $(CPPFLAGS) -fPIC -c -o $@ $<

$(SDL_LIB): $(OBJ_DIR)/SDL.o
	@mkdir -p $(dir $@)
	@$(CC) -shared -o $@ $^

-include $(DEPS)

clean:
	@rm -rf $(OBJ_DIR) $(LIB_DIR)
	@printf "\033[0;32mCleanup successful.\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[0;32mFull cleanup successful.\033[0m\n"

re: fclean all

.PHONY: all clean fclean re
