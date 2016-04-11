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



  // while(!isFullyConnected()) {
  //   cout << "removing random wall" << endl;
  //   removeRandomWall();
  // }
  removeRandomWall();

  for(int i = 0; i < length; i++) {
    cout << horzWalls[i] << " ";
  }
  cout << endl;

}

void Maze::removeRandomWall() {
  int randCell = rand() % n * m;
  int randWall = rand() % 4;

  randCell = 0;
  randWall = 1;

  cout << "attempting to remove " << randWall << " from cell " << randCell << endl;

  if(!beenRemoved(randCell, randWall) && !areConnected(randCell, randWall)) {
    if(randWall == 0)
      horzWalls[randCell - n] = 1;
    else if(randWall == 1)
      vertWalls[randCell] = 1;
    else if(randWall == 2)
      vertWalls[randCell - 1] = 1;
    else if(randWall == 3)
      horzWalls[randCell] = 1; cout << randCell << endl;
  }

  printMaze();
}

bool Maze::beenRemoved(int cell, int wall) {
  if(wall == 0 && horzWalls[cell - n] == 1)
    return true;
  else if(wall == 3 && horzWalls[cell] == 1)
    return true;
  else if(wall == 1 && horzWalls[cell] == 1)
    return true;
  else if(wall == 2 && horzWalls[cell - 1] == 1)
    return true;
  else
    cout << "false" << endl; return false;
}

bool Maze::areConnected(int cell, int wall) {
  int newCell;

  switch(wall) {
    case 0 : newCell = cell - n;
    case 1 : newCell = cell + 1;
    case 2 : newCell = cell - 1;
    case 3 : newCell = cell + n;
  }

  if(getRoot(cell) == getRoot(newCell))
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
      else if(j == n - 1)
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
