NAME = Nibbler

LIB_DIR = requirements/libs
SRC_DIR = requirements/functions
OBJ_DIR = .objs

AUDIO_LIB = $(LIB_DIR)/Audio.so
GL_LIB = $(LIB_DIR)/GL.so
SDL_LIB = $(LIB_DIR)/SDL.so
SFML_LIB = $(LIB_DIR)/SFML.so

CC = g++
CPPFLAGS = -Wall -Wextra -Werror -MMD -MP -gdwarf-2
DIRDUP = mkdir -p $(@D)

MAIN_SRC = requirements/main.cpp
MAIN_OBJ = $(OBJ_DIR)/main.o

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

all: $(NAME) $(AUDIO_LIB) $(GL_LIB) $(SDL_LIB) $(SFML_LIB) 

$(NAME): $(OBJS) $(MAIN_OBJ)
	@printf "\033[0;32mCompilation successful.\033[0m\n"
	@$(CC) $(OBJS) $(MAIN_OBJ) -lSDL2 -lSDL2_ttf -lGL -lglfw -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-window -o $(NAME)


$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@$(DIRDUP)
	@$(CC) $(CPPFLAGS) -c -o $@ $<


$(MAIN_OBJ): $(MAIN_SRC)
	@$(DIRDUP)
	@$(CC) $(CPPFLAGS) -c -o $@ $<


$(OBJ_DIR)/Audio.o: $(SRC_DIR)/Audio.cpp
	@$(DIRDUP)
	@$(CC) $(CPPFLAGS) -shared -fPIC -c -o $@ $<

$(OBJ_DIR)/Errors.o: $(SRC_DIR)/Errors.cpp
	@$(DIRDUP)
	@$(CC) $(CPPFLAGS) -shared -fPIC -c -o $@ $<

$(OBJ_DIR)/Library.o: $(SRC_DIR)/Library.cpp
	@$(DIRDUP)
	@$(CC) $(CPPFLAGS) -shared -fPIC -c -o $@ $<

$(OBJ_DIR)/GL.o: $(SRC_DIR)/GL.cpp
	@$(DIRDUP)
	@$(CC) $(CPPFLAGS) -shared -fPIC -c -o $@ $<

$(OBJ_DIR)/SDL.o: $(SRC_DIR)/SDL.cpp
	@$(DIRDUP)
	@$(CC) $(CPPFLAGS) -shared -fPIC -c -o $@ $<

$(OBJ_DIR)/SFML.o: $(SRC_DIR)/SFML.cpp
	@$(DIRDUP)
	@$(CC) $(CPPFLAGS) -shared -fPIC -c -o $@ $<


$(AUDIO_LIB): $(OBJ_DIR)/Audio.o
	@mkdir -p $(dir $@)
	@$(CC) -shared -o $@ $^

$(GL_LIB): $(OBJ_DIR)/GL.o $(OBJ_DIR)/Library.o $(OBJ_DIR)/Errors.o
	@mkdir -p $(dir $@)
	@$(CC) -shared -o $@ $^

$(SDL_LIB): $(OBJ_DIR)/SDL.o $(OBJ_DIR)/Library.o $(OBJ_DIR)/Errors.o
	@mkdir -p $(dir $@)
	@$(CC) -shared -o $@ $^

$(SFML_LIB): $(OBJ_DIR)/SFML.o $(OBJ_DIR)/Library.o $(OBJ_DIR)/Errors.o
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