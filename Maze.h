#ifndef MAZE_H
#define MAZE_H

class Maze {
public:
  Maze(int n, int m);
  void printMaze();

private:
  int n;
  int m;
  int length;

  int* disjointSet;
  int* horzWalls;
  int* vertWalls;

  void generateMaze();
  void initializeArrays();
};

#endif
