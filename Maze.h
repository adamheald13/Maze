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
  bool isFullyConnected();
  void removeRandomWall();
  bool beenRemoved(int cell, int wall);
  bool areConnected(int cell, int wall);
  int getRoot(int cell);
  int getNewCell(int cell, int wall);
};

#endif
