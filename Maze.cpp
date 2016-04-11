#include <iostream>
#include <stdlib.h>
#include "Maze.h"
using namespace std;

Maze::Maze(int n, int m) {
  srand(1);

  this->n = n;
  this->m = m;
  this->length = n * m;

  generateMaze();
}

void Maze::generateMaze() {
  initializeArrays();

  while(!isFullyConnected()) {
    removeRandomWall();
  }
}

void Maze::removeRandomWall() {
  int randCell = rand() % (n * m);
  int randWall = rand() % 4;

  if(!beenRemoved(randCell, randWall) && !areConnected(randCell, randWall)) {
    //mark wall removed
    if(randWall == 0)
      horzWalls[randCell - n] = 1;
    else if(randWall == 1)
      vertWalls[randCell] = 1;
    else if(randWall == 2)
      vertWalls[randCell - 1] = 1;
    else if(randWall == 3)
      horzWalls[randCell] = 1;

    //add to disjoint set
    int root = getRoot(randCell);
    int newRoot = getRoot(getNewCell(randCell, randWall));

    if(root < newRoot)
      disjointSet[newRoot] = root;
    else
      disjointSet[root] = newRoot;
  }

  printMaze();
}

int Maze::getNewCell(int cell, int wall) {
  int newCell = 0;

  switch(wall) {
    case 0 : newCell = cell - n;
    break;
    case 1 : newCell = cell + 1;
    break;
    case 2 : newCell = cell - 1;
    break;
    case 3 : newCell = cell + n;
    break;
  }

  return newCell;
}

bool Maze::beenRemoved(int cell, int wall) {
  //cells along left edge of maze can't have their left wall removed
  if(cell % n == 0 && wall == 2)
    return true;

  //cells in bottom row of maze can't have their bottom wall removed
  if(cell == n * (m - 1) && wall == 3)
    return true;

  if(cell < n && wall == 0)
    return true;

  if(cell == 0 && wall == 2)
    return true;

  if(wall == 0 && horzWalls[cell - n] == 1)
    return true;
  else if(wall == 3 && horzWalls[cell] == 1)
    return true;
  else if(wall == 1 && vertWalls[cell] == 1)
    return true;
  else if(wall == 2 && horzWalls[cell - 1] == 1)
    return true;
  else
    return false;
}

bool Maze::areConnected(int cell, int wall) {
  if(getRoot(cell) == getRoot(getNewCell(cell, wall)))
    return true;
  else
    return false;
}

int Maze::getRoot(int cell) {
  if(disjointSet[cell] == -1)
    return cell;
  else
    return getRoot(disjointSet[cell]);
}

void Maze::initializeArrays() {
  this->disjointSet = new int[length];
  this->horzWalls = new int[length];
  this->vertWalls = new int[length];

  for(int i = 0; i < length; i++) {
    disjointSet[i] = -1;

    //set to one if on bottom row of walls as they are edge walls
    if(i >= length - n)
      horzWalls[i] = 1;
    else
      horzWalls[i] = 0;

    //set to 1 because they are an outer edge in the maze and cannot be removed.
    if((i + 1) % n == 0)
      vertWalls[i] = 1;
    else //inner wall edge
      vertWalls[i] = 0;
  }
}

bool Maze::isFullyConnected() {
  int num = 0;

  for(int i = 0; i < length; i++) {
    if(disjointSet[i] == -1)
      num++;
  }

  if(num == 1)
    return true;
  else
    return false;
}

void Maze::printMaze() {
  //print top row of external walls
  for(int i = 0; i < n; i++) {
    cout << " _";
  }
  cout << endl;

  //each row
  int l = 0;
  for(int j = 0; j < m; j++) {
    cout << "|";


    for(int k = 0; k < n; k++) {
      if(horzWalls[l] == 0)
        cout << "_";
      else if(j == m - 1)
        cout << "_";
      else
        cout << " ";

      if(vertWalls[l] == 0)
        cout << "|";
      else if(k == n - 1)
        cout << "";
      else
        cout << " ";
      l++;
    }

    cout << "|" << endl;
  }
}
