//
// Created by ’≈≥…√Ù on 2019-05-14.
//

#include "Riders.h"

Riders::Riders(int num, int x, int y) {
  for (int i = 0; i < num; i++) {
    Rider rider = Rider(riders.size(), x, y);
    riders.push_back(rider);
  }
}

Riders::Riders() { riders.clear(); }

void Riders::changeCoordinateOfAllRidersByRoutes() {
  for (int i = 0; i < riders.size(); i++) {
    riders[i].changeCoordinateOfSelfByRoutes();
  }
}

void Riders::updateAllRidertaskListStateAfterMovement(int time) {
  for (int i = 0; i < riders.size(); i++) {
    riders[i].updateMytaskListStateAfterMovement(time);
  }
}

void Riders::updatetheRouteOfAllRiders() {
  for (int i = 0; i < riders.size(); i++) {
    riders[i].updateMytheRoute();
  }
}

int Riders::getTheFinalProfit() {
  int total = 0;
  for (auto temp : riders) {
    total += temp.getTheTotalProfit();
  }
  return total;
}

void Riders::increaseTheRiders(int num, int x, int y) {
  for (int i = 0; i < num; i++) {
    Rider rider = Rider(riders.size(), x, y);
    riders.push_back(rider);
  }
}

bool Riders::distributeTheTask(int riderId, int no, int receiveTime1,
                               bool contributionState1, int restaurantAddX,
                               int restaurantAddY, int customerAddX,
                               int customerAddY) {
  if (riderId >= riders.size()) return false;
  riders[riderId].theTaskList.addBackCustomTasksItem(
      no, receiveTime1, contributionState1, riderId, restaurantAddX,
      restaurantAddY, customerAddX, customerAddY);
  return true;
}

void Riders::allRidersActionLoop(int time) {
  updatetheRouteOfAllRiders();
  changeCoordinateOfAllRidersByRoutes();
  updateAllRidertaskListStateAfterMovement(time);
}

void Riders::tellAllRidersInfo() {
  std::cout << "*******************************************************\n";
  std::cout << "AllRidersInfo:\n";
  for (auto temp : riders) temp.tellTheRider();
  std::cout << "*******************************************************\n";
}
