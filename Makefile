CC = g++

CC_DEBUG = @$(CC) -std=c++11
CC_RELEASE = @$(CC) -std=c++11 -O3 -DNDEBUG

G_DEPS = src/core/*.cpp

G_INC = -I.

canvas: $(G_DEPS) tests/CanvasTest.cpp
	$(CC_DEBUG) $(G_INC) $(G_DEPS) tests/CanvasTest.cpp -o canvas

matrix: $(G_DEPS) tests/MatrixTest.cpp
	$(CC_DEBUG) $(G_INC) $(G_DEPS) tests/MatrixTest.cpp -o matrix

transformations: $(G_DEPS) tests/TransformationsTest.cpp
	$(CC_DEBUG) $(G_INC) $(G_DEPS) tests/TransformationsTest.cpp -o transformations

spheres: $(G_DEPS) tests/SpheresTest.cpp
	$(CC_DEBUG) $(G_INC) $(G_DEPS) tests/SpheresTest.cpp -o spheres

phong: $(G_DEPS) tests/PhongTest.cpp
	$(CC_DEBUG) $(G_INC) $(G_DEPS) tests/PhongTest.cpp -o phong

world: $(G_DEPS) tests/WorldTest.cpp
	$(CC_DEBUG) $(G_INC) $(G_DEPS) tests/WorldTest.cpp -o world

clean: 
	@rm -rf canvas matrix transformations spheres phong world *.ppm