all:
	g++ -Isrc/include -Lsrc/lib -D USE_WINDOWS -o main Engine.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 