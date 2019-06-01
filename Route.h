//
// Created by 张成敏 on 2019-05-04.
//

#ifndef TAKEAWAYASSIGNMENT0_1_ROUTE_H
#define TAKEAWAYASSIGNMENT0_1_ROUTE_H

#include <deque>
#include <iostream>
#include "Coordinate.h"
#include <vector>

class Route {
 public:
  std::deque<Coordinate> routes;
  Route();
  explicit Route(int num);
  // 给定两个骑手可在位置点算出其中的最短路径图并生成这样一个route
  explicit Route(Coordinate begin, Coordinate end);
  void tellTheRoute();
  void addFrontCustomCoordinate(int x1, int y1);
  void addBackCustomCoordinate(int x1, int y1);
  // += 运算符实现
  bool increaseMyselfFromAnotherRoute(Route route1);
  
};

#endif  // TAKEAWAYASSIGNMENT0_1_ROUTE_H
