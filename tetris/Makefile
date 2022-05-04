CC = g++
INC = -I. -I/opt/homebrew/Cellar/glfw/3.3.6/include -I/opt/homebrew/Cellar/glew/2.2.0_1/include -I/opt/homebrew/Cellar/glm/0.9.9.8/include
LIB_DIRS = -L/opt/homebrew/Cellar/glfw/3.3.6/lib -L/opt/homebrew/Cellar/glew/2.2.0_1/lib -framework OpenGL
LIBS = -lglfw.3.3 -lGLEW.2.2.0
SRCS = main.cpp game.cpp play.cpp ranking.cpp block.cpp input.cpp window.cpp field.cpp graphic.cpp shaders/shader.cpp
OBJ = main.o game.o play.o ranking.o block.o input.o window.o field.o graphic.o shader.o

main : $(OBJ)
	$(CC) $(INC) $(OBJ) $(LIB_DIRS) $(LIBS) -o main

main.o : main.cpp
	$(CC) $(INC) $(LIB_DIRS) $(LIBS) -c main.cpp -o main.o

game.o : game.cpp
	$(CC) $(INC) $(LIB_DIRS) $(LIBS) -c game.cpp -o game.o

play.o : play.cpp
	$(CC) $(INC) $(LIB_DIRS) $(LIBS) -c play.cpp -o play.o

ranking.o : ranking.cpp
	$(CC) $(INC) $(LIB_DIRS) $(LIBS) -c ranking.cpp -o ranking.o

block.o : block.cpp
	$(CC) $(INC) $(LIB_DIRS) $(LIBS) -c block.cpp -o block.o

input.o : input.cpp
	$(CC) $(INC) $(LIB_DIRS) $(LIBS) -c input.cpp -o input.o

window.o : window.cpp
	$(CC) $(INC) $(LIB_DIRS) $(LIBS) -c window.cpp -o window.o

field.o : field.cpp
	$(CC) $(INC) $(LIB_DIRS) $(LIBS) -c field.cpp -o field.o

graphic.o : graphic.cpp
	$(CC) $(INC) $(LIB_DIRS) $(LIBS) -c graphic.cpp -o graphic.o

shader.o : shaders/shader.cpp
	$(CC) $(INC) $(LIB_DIRS) $(LIBS) -c shaders/shader.cpp -o shader.o

clean :
	rm -rf *.o main
