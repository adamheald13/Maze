#include <iostream>
#include "Maze.h"
using namespace std;

Maze::Maze(int n, int m) {
  this->n = n;
  this->m = m;
  this->length = 5;

  generateMaze();
}

void Maze::generateMaze() {
  initializeArrays();

}

void Maze::initializeArrays() {
  this->disjointSet = new int[length];
  this->horzWalls = new int[length];
  this->vertWalls = new int[length];

  for(int i = 0; i < length; i++) {
    disjointSet[i] = -1;
    horzWalls[i] = 0;
    vertWalls[i] = 0;
  }
}

void Maze::printMaze() {
  cout << "Width: " << n << endl;
  cout << "Height: " << m << endl;
}
