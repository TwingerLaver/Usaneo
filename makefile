PROJECTNAME = usaneo
OUTPUT_DIR = build

INCLUDE_DIRS = -Iinclude -Iinclude/imgui
LIB_DIRS = -Llib
LIBS = -lmingw32 -lSDL2main -lSDL2 -LSDL2_image -lSDL2_mixer

SRC = $(wildcard src/*.cpp) $(wildcard imgui/*.cpp)

all:
	mkdir -p $(OUTPUT_DIR)
	g++ $(SRC) -o $(OUTPUT_DIR)/$(PROJECTNAME).exe $(INCLUDE_DIRS) $(LIB_DIRS) $(LIBS)
