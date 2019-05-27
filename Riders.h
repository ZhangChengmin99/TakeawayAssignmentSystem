//
// Created by ’≈≥…√Ù on 2019-05-14.
//

#ifndef TAKEAWAYASSIGNMENT0_1_RIDERS_H
#define TAKEAWAYASSIGNMENT0_1_RIDERS_H

#include <deque>
#include "Rider.h"
#include "OutputDataOfthisTime.h"

class Riders {
 public:
  std::deque<Rider> riders;
  Riders();
  explicit Riders(int num, int x, int y);
  void increaseTheRiders(int num, int x, int y);
  int getTheFinalProfit();
  void updatetheRouteOfAllRiders();
  void updateAllRidertaskListStateAfterMovement(int time);
  void changeCoordinateOfAllRidersByRoutes();
  OutputDataOfthisTime returnOutputDataOfthisTimeAndPopFinishedTasks(int time);
  OutputDataOfthisTime allRidersActionLoopAndReturnProfit(int time);
  void tellAllRidersInfo();
  bool distributeTheTask(int riderId, int no, int receiveTime1,
                         bool contributionState1, int restaurantAddX,
                         int restaurantAddY, int customerAddX,
                         int customerAddY);
  int stepDistance(int riderX, int riderY, int destinationX, int destinationY);
};

#endif  // TAKEAWAYASSIGNMENT0_1_RIDERS_H
