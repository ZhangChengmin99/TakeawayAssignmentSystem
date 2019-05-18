//
// Created by ’≈≥…√Ù on 2019-04-25.
//

#ifndef TAKEAWAYASSIGNMENT0_1_RIDER_H
#define TAKEAWAYASSIGNMENT0_1_RIDER_H

#include "Route.h"
#include "TasksItemList.h"

class Rider {
 private:
  int id;
  int totalProfitGet;

 public:
  Coordinate coordinateOfSelf;
  TasksItemList theTaskList;
  Route theRoute;
  // constructor
  Rider();
  explicit Rider(int id1, int x, int y);
  // movement
  bool moveFromChange(Coordinate::change change1);
  bool changeCoordinateOfSelf(Coordinate outCoordinate);
  bool changeCoordinateOfSelfByRoutes();
  void updateMytheRoute();
  int intimateMyRouteAndReturnIncreasedStepsNum(int num1, int receiveTime1,
                                       bool contributionState1, int riderId1,
                                       int restaurantAddX, int restaurantAddY,
                                       int customerAddX, int customerAddY);
  int getTheTotalProfit();
  void tellTheRider();
  void updateMytaskListStateAfterMovement(int time);
  int returnThisTurnCompletedTaskProfitAndPopIt();
};

#endif  // TAKEAWAYASSIGNMENT0_1_RIDER_H
