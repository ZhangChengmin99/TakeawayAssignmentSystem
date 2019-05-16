//
// Created by 张成敏 on 2019-04-25.
//

#ifndef TAKEAWAYASSIGNMENT0_1_COORDINATE_H
#define TAKEAWAYASSIGNMENT0_1_COORDINATE_H
#define BIRTHPOSITION_X 8
#define BIRTHPOSITION_Y 7

#include <math.h>
#include <stdlib.h>
#include <iostream>

class Coordinate {
 private:
  int x;
  int y;

 public:
  enum change {
    leftUp,
    leftDown,
    rightUp,
    rightDown,
    rightStraight,
    leftStraight,
    upStraight,
    downStraight,
  };
  // 默认构造器
  Coordinate();
  // 便利构造器
  explicit Coordinate(int x1, int y1);
  // 更改坐标函数(最大权限)
  void changeCoordinate(int x1, int y1);
  // 坐标向可移动方向移动(在路上的坐标)
  bool move(change change1);
  // 坐标通过另一个坐标进行移动(在路上的可移动方向)
  bool moveThourghtheIndsideCoordinate(Coordinate coordinate2);
  // 判断一个坐标是否在路上(在路上返回true否则false)
  bool roadJudge();
  // 判断两个坐标是否相邻
  bool insideJudgeFromAnother(Coordinate coordinate2);
  // 报告位置输出
  void tellPosition();
};

#endif  // TAKEAWAYASSIGNMENT0_1_COORDINATE_H
