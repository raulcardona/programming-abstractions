/*
 * File: FindSolutionPath.cpp
 * --------------------------
 * This program finds a solution path in a maze.
 */

#include <iostream>
#include <string>
#include "direction.h"
#include "gwindow.h"
#include "maze.h"
#include "point.h"
#include "vector.h"
using namespace std;

/* Function prototypes */

int shortestPathLength(Maze &maze, Point start);
bool findSolutionPath(Maze & maze, Point start, Vector<Point> & path, Vector<int> &count);
Point adjacentPoint(Point start, Direction dir);
void unmarkAllSquares(Maze & maze);
int getLowestCount(Vector<int> vec);

/* Main program */

int main() {
    GWindow gw;
    Maze maze("maze.txt", gw);
    cout << "The shortest path is " << shortestPathLength(maze, maze.getStartPosition()) << " spaces long." << endl;
    return 0;
}

int shortestPathLength(Maze &maze, Point start) {
    Vector<int> count;
    Vector<Point> path;
    if (findSolutionPath(maze, maze.getStartPosition(), path, count) || count.size() > 0) {
        return getLowestCount(count);
    } else {
        return -1;
    }
}

int getLowestCount(Vector<int> vec) {
    int total = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] < total) {
            total = vec[i];
        }
    }
    return total;
}

bool findSolutionPath(Maze & maze, Point start, Vector<Point> & path, Vector<int> &count) {
    if (maze.isOutside(start)) {
        count.add(path.size());
        return false;
    }
    if (maze.isMarked(start)) return false;
    path.add(start);
    maze.markSquare(start);
    for (Direction dir = NORTH; dir <= WEST; dir++) {
       if (!maze.wallExists(start, dir)) {
          Point neighbor = adjacentPoint(start, dir);
          if (findSolutionPath(maze, neighbor, path, count)) {
             return true;
            }
        }
    }
    path.remove(path.size() - 1);
    maze.unmarkSquare(start);
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
