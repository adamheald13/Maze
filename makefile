Lab10: main.o Maze.o
	g++ -g main.o Maze.o -o Lab10
main.o: main.cpp
	g++ -g -c main.cpp
Maze.o: Maze.cpp Maze.h
	g++ -g -c Maze.cpp
clean:
	rm *.o Lab10
