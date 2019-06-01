//
// Created by �ų��� on 2019-05-04.
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
  // �����������ֿ���λ�õ�������е����·��ͼ����������һ��route
  explicit Route(Coordinate begin, Coordinate end);
  void tellTheRoute();
  void addFrontCustomCoordinate(int x1, int y1);
  void addBackCustomCoordinate(int x1, int y1);
  // += �����ʵ��
  bool increaseMyselfFromAnotherRoute(Route route1);
  
};

#endif  // TAKEAWAYASSIGNMENT0_1_ROUTE_H
