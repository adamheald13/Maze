#include <iostream>
#include "Maze.h"
using namespace std;

int main() {
  int n = 0;
  int m = 0;

  cout << "Please enter the width of the maze: ";
  cin >> n;
  cout << "Please enter the height of the maze: ";
  cin >> m;

  Maze maze(n, m);

  // maze.printMaze();

  return 0;
}
