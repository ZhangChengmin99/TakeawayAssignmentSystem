//
// Created by ’≈≥…√Ù on 2019-05-03.
//

#include "TasksItem.h"

TasksItem::TasksItem() {
  num = -1;
  receiveTime = -1;
  contributionState = false;
  riderId = -1;
  fetchGoodState = false;
  sendGoodState = false;
  arrivedTime = -1;
  profit = 0;
  restaurantAdd = Coordinate();
  customerAdd = Coordinate();
}

TasksItem::TasksItem(int num1, int receiveTime1, bool contributionState1,
                     int riderId1, int restaurantAddX, int restaurantAddY,
                     int customerAddX, int customerAddY) {
  num = num1;
  receiveTime = receiveTime1;
  contributionState = contributionState1;
  riderId = riderId1;
  fetchGoodState = false;
  sendGoodState = false;
  arrivedTime = -1;
  profit = 0;
  restaurantAdd.changeCoordinate(restaurantAddX, restaurantAddY);
  customerAdd.changeCoordinate(customerAddX, customerAddY);
}

void TasksItem::changeContributionDetail(bool state, int riderId1) {
  contributionState = state;
  riderId = riderId1;
}

void TasksItem::changeFetchGoodState(bool state) { fetchGoodState = state; }

void TasksItem::changeSendDetail(bool state, int arrivedTime1) {
  sendGoodState = state;
  arrivedTime = arrivedTime1;
  if ((arrivedTime != -1) && (receiveTime != -1)) {
    if (arrivedTime - receiveTime < 31) {
      profit = 10;
    } else {
      profit = -50;
    }
  }
}

int TasksItem::getProfit() { return profit; }

void TasksItem::tellTheTasksItem() {
  std::cout << "********************************\n";
  std::cout << "The TasksItem Detail:\n";
  std::cout << "Num: " << num << '\n'
            << "ReceiveTime: " << receiveTime << '\n'
            << "ContributionState: " << contributionState << '\n';
  std::cout << "RiderId: " << riderId << '\n'
            << "FetchGoodState: " << fetchGoodState << '\n'
            << "SendGoodState: " << sendGoodState << '\n';
  std::cout << "The restaurantAdd:\n";
  restaurantAdd.tellPosition();
  std::cout << "The customerAdd:\n";
  customerAdd.tellPosition();
  std::cout << "ArrivedTime: " << arrivedTime << '\n'
            << "Profit: " << profit << "$\n";
  std::cout << "********************************\n";
}
