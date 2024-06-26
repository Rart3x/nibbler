NAME = Nibbler

SRC_DIR = requirements/functions
OBJ_DIR = .objs
LIB_DIR = .libs

LIB_NAME1 = openGL.a
# LIB_NAME2 = openGL.a
# LIB_NAME3 = openGL.a

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

MAIN_SRC = requirements/main.cpp
MAIN_OBJ = $(OBJ_DIR)/main.o

CC = g++
CPPFLAGS = -Wall -Wextra -Werror -MMD -MP -gdwarf-2

DIRDUP = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJ) $(LIB_DIR)/$(LIB_NAME1)
	@printf "\033[0;32mCompilation successful.\033[0m\n"
	@$(CC) $(OBJS) $(MAIN_OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@$(DIRDUP)
	@$(CC) $(CPPFLAGS) -c -o $@ $<

$(MAIN_OBJ): $(MAIN_SRC)
	@$(DIRDUP)
	@$(CC) $(CPPFLAGS) -c -o $@ $<

$(LIB_DIR)/$(LIB_NAME1): $(filter-out $(MAIN_SRC), $(SRCS))
	@$(DIRDUP)
	@ar rcs $@ $^

-include $(DEPS)

clean:
	@rm -rf $(OBJ_DIR) $(LIB_DIR)
	@printf "\033[0;32mCleanup successful.\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[0;32mFull cleanup successful.\033[0m\n"

re: fclean all

.PHONY: all clean fclean re