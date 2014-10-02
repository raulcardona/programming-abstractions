// 6,317 recursive calls with unmarkSquare included.
// 63 recursive calls without it.
// Wow!

#include <iostream>
#include <string>
#include "direction.h"
#include "gwindow.h"
#include "maze.h"
#include "point.h"
#include "vector.h"
using namespace std;

/* Function prototypes */

bool findSolutionPath(Maze & maze, Point start, Vector<Point> & path, int &recursiveCalls);
Point adjacentPoint(Point start, Direction dir);
void unmarkAllSquares(Maze & maze);

/* Main program */

int main() {
   GWindow gw;
   Maze maze("maze.txt", gw);
   Vector<Point> path;
    int recursiveCalls = 0;
   if (findSolutionPath(maze, maze.getStartPosition(), path, recursiveCalls)) {
      foreach (Point pt in path) {
         cout << pt << endl;
      }
   }
    cout << recursiveCalls << endl;
   return 0;
}

bool findSolutionPath(Maze & maze, Point start, Vector<Point> & path, int &recursiveCalls) {
    recursiveCalls++;
   if (maze.isOutside(start)) return true;
   if (maze.isMarked(start)) return false;
   path.add(start);
   maze.markSquare(start);
   for (Direction dir = NORTH; dir <= WEST; dir++) {
      if (!maze.wallExists(start, dir)) {
         Point neighbor = adjacentPoint(start, dir);
         if (findSolutionPath(maze, neighbor, path, recursiveCalls)) {
            return true;
         }
      }
   }
   path.remove(path.size() - 1);
    //maze.unmarkSquare(start);
   return false;
}

Point adjacentPoint(Point start, Direction dir) {
   switch (dir) {
    case NORTH: return Point(start.getX(), start.getY() - 1);
    case EAST:  return Point(start.getX() + 1, start.getY());
    case SOUTH: return Point(start.getX(), start.getY() + 1);
    case WEST:  return Point(start.getX() - 1, start.getY());
   }
   return start;
}

void unmarkAllSquares(Maze & maze) {
   for (int x = 0; !maze.isOutside(Point(x, 0)); x++) {
      for (int y = 0; !maze.isOutside(Point(0, y)); y++) {
         maze.unmarkSquare(Point(x, y));
      }
   }
}
