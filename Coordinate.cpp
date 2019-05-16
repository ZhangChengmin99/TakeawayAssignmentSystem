//
// Created by 张成敏 on 2019-04-25.
//

#include "Coordinate.h"

Coordinate::Coordinate() {
  x = BIRTHPOSITION_X;
  y = BIRTHPOSITION_Y;
}

Coordinate::Coordinate(int x1, int y1) {
  x = x1;
  y = y1;
}

void Coordinate::changeCoordinate(int x1, int y1) {
  x = x1;
  y = y1;
}

bool Coordinate::move(Coordinate::change change1) {
  // 判断是否为建筑物坐标
  if (x % 2 || y % 2) {
    // 分析传入指令(包含容错机制)
    switch (change1) {
      case leftUp: {
        if (y == 0 || x == 0) {
          return false;
        } else {
          x -= 1;
          y -= 1;
          break;
        }
      }
      case leftDown: {
        if (x == 0 || y == 16) {
          return false;
        } else {
          x -= 1;
          y += 1;
          break;
        }
      }
      case rightUp: {
        if (x == 16 || y == 0) {
          return false;
        } else {
          x += 1;
          y -= 1;
          break;
        }
      }
      case rightDown: {
        if (x == 16 || y == 16) {
          return false;
        } else {
          x += 1;
          y += 1;
          break;
        }
      }
      case rightStraight: {
        if ((y % 2 == 1) && (x != 16)) {
          x += 2;
          break;
        } else {
          return false;
        }
      }
      case leftStraight: {
        if ((y % 2 == 1) && (x != 0)) {
          x -= 2;
          break;
        } else {
          return false;
        }
      }
      case upStraight: {
        if ((x % 2 == 1) && (y != 0)) {
          y -= 2;
          break;
        } else {
          return false;
        }
      }
      case downStraight: {
        if ((x % 2 == 1) && (y != 16)) {
          y += 2;
          break;
        } else {
          return false;
        }
      }
    }
    return true;
  } else {
    std::cout << "Can't move a building.\n";
    return false;
  }
}

bool Coordinate::insideJudgeFromAnother(Coordinate coordinate2) {
  return (x == coordinate2.x && abs(y - coordinate2.y) == 1) ||
         (y == coordinate2.y && abs(x - coordinate2.x) == 1);
}

void Coordinate::tellPosition() {
  if (roadJudge()) {
    std::cout << "The road position: ";
  } else {
    std::cout << "The building position: ";
  }
  std::cout << "x: " << x << " , y: " << y << ".\n";
}

bool Coordinate::moveThourghtheIndsideCoordinate(Coordinate coordinate2) {
  if (x - coordinate2.x == 1 && y - coordinate2.y == 1) return move(leftUp);
  if (x - coordinate2.x == -1 && y - coordinate2.y == 1) return move(rightUp);
  if (x - coordinate2.x == 1 && y - coordinate2.y == -1) return move(leftDown);
  if (x - coordinate2.x == -1 && y - coordinate2.y == -1)
    return move(rightDown);
  if (y == coordinate2.y && x - coordinate2.x == 2) return move(leftStraight);
  if (y == coordinate2.y && x - coordinate2.x == -2) return move(rightStraight);
  if (x == coordinate2.x && y - coordinate2.y == 2) return move(upStraight);
  if (x == coordinate2.x && y - coordinate2.y == -2) return move(downStraight);
  return false;
}

bool Coordinate::roadJudge() { return x % 2 == 1 || y % 2 == 1; }
