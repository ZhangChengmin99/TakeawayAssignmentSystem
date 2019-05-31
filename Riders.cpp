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

OutputDataOfthisTime Riders::returnOutputDataOfthisTimeAndPopFinishedTasks(int time) {
  OutputDataOfthisTime tempOutput;
  for (int i = 0; i < riders.size(); i++) {
    tempOutput.increaseMySelfFromAnotherOutput(riders.at(i).returnOutputDataOfthisTimeAndPopFinishedTasks(time));
  }
  return tempOutput;
}

void Riders::updateAllRidertaskListStateAfterMovement(int time) {
  for (int i = 0; i < riders.size(); i++) {
    riders[i].updateMytaskListStateAfterMovement(time);
  }
}

void Riders::updatetheRouteOfAllRiders(int time) {
  for (int i = 0; i < riders.size(); i++) {
    riders[i].updateMytheRoute(time);
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

int Riders::stepDistance(int riderX, int riderY, int destinationX,
                         int destinationY) {
  int theStepDistance;
  if (riderX == destinationX) {
    theStepDistance = (abs(riderY - destinationY) - 1) / 2;
  } else if (riderY == destinationY) {
    theStepDistance = (abs(riderX - destinationX) - 1) / 2;
  } else if (riderY > destinationY) {
    theStepDistance =
        (abs(riderX - destinationX) + abs(riderY - destinationY - 1)) / 2;
  } else if (riderY < destinationY) {
    theStepDistance =
        (abs(riderX - destinationX) + abs(riderY - destinationY - 1)) / 2;
  }
  return theStepDistance;
}

OutputDataOfthisTime Riders::allRidersUpdateTasklist(int time) {
  updateAllRidertaskListStateAfterMovement(time);
  return returnOutputDataOfthisTimeAndPopFinishedTasks(time);
}

void Riders::tellAllRidersInfo() {
  std::cout << "*******************************************************\n";
  std::cout << "AllRidersInfo:\n";
  for (auto temp : riders) temp.tellTheRider();
  std::cout << "*******************************************************\n";
}

bool Riders::judgeAllRidersTasklistEmpty() { 
	bool judge = true;
	for(int i = 0 ; i < riders.size();i++) {
		if(!riders.at(i).theTaskList.taskItems.empty())
			judge = false;
	}
	return judge; }

void Riders::theOutputOfRiders() {
  for (int i = 0 ;i <riders.size();i++) {
    riders.at(i).outPutThisTimeANDresetTempBesidesLOC();
  }
}
