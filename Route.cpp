//
// Created by ÕÅ³ÉÃô on 2019-05-04.
//

#include "Route.h"

Route::Route() {
  Coordinate coordinate;
  routes.insert(routes.begin(), 0, coordinate);
}

Route::Route(int num) {
  Coordinate coordinate;
  routes.insert(routes.begin(), num, coordinate);
}

void Route::tellTheRoute() {
  std::cout << "The route of this rider is:\n";
  for (auto x : routes) {
    x.tellPosition();
  }
}

void Route::addFrontCustomCoordinate(int x1, int y1) {
  Coordinate coordinate = Coordinate(x1, y1);
  routes.push_front(coordinate);
}

void Route::addBackCustomCoordinate(int x1, int y1) {
  Coordinate coordinate = Coordinate(x1, y1);
  routes.push_back(coordinate);
}