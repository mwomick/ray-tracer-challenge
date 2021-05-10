CC = g++

CC_DEBUG = @$(CC) -std=c++11
CC_RELEASE = @$(CC) -std=c++11 -O3 -DNDEBUG

G_DEPS = src/core/*.cpp

G_INC = -I.

canvas: $(G_DEPS) tests/CanvasTest.cpp
	$(CC_DEBUG) $(G_INC) $(G_DEPS) tests/CanvasTest.cpp -o canvas

matrix: $(G_DEPS) tests/MatrixTest.cpp
	$(CC_DEBUG) $(G_INC) $(G_DEPS) tests/MatrixTest.cpp -o matrix

clean: 
	@rm -rf canvas matrix *.ppm