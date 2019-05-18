//
// Created by ’≈≥…√Ù on 2019-05-04.
//

#include "TasksItemList.h"

TasksItemList::TasksItemList() {
  TasksItem taskItem;
  taskItems.insert(taskItems.begin(), 0, taskItem);
}

TasksItemList::TasksItemList(int num) {
  TasksItem taskItem;
  taskItems.insert(taskItems.begin(), num, taskItem);
}

int TasksItemList::returnTheCompletedTaskProfitAndPopIt() {
  int thisTurnProfit = 0;
  for (int i = 0; i < taskItems.size(); i++) {
    if (taskItems.at(i).sendGoodState) {
      thisTurnProfit += taskItems.at(i).getProfit();
      taskItems.erase(taskItems.begin()+i);
    }
  }
  return thisTurnProfit;
}

void TasksItemList::tellTasksItemList() {
  std::cout << "The tasksListBegin of this rider:\n";
  for (auto x : taskItems) x.tellTheTasksItem();
  std::cout << "The tasksListEnd of this rider:\n";
}

void TasksItemList::addBackCustomTasksItem(int num1, int receiveTime1,
                                           bool contributionState1,
                                           int riderId1, int restaurantAddX,
                                           int restaurantAddY, int customerAddX,
                                           int customerAddY) {
  TasksItem taskItem =
      TasksItem(num1, receiveTime1, contributionState1, riderId1,
                restaurantAddX, restaurantAddY, customerAddX, customerAddY);
  taskItems.push_back(taskItem);
}

void TasksItemList::addFrontCustomTasksItem(int num1, int receiveTime1,
                                            bool contributionState1,
                                            int riderId1, int restaurantAddX,
                                            int restaurantAddY,
                                            int customerAddX,
                                            int customerAddY) {
  TasksItem taskItem =
      TasksItem(num1, receiveTime1, contributionState1, riderId1,
                restaurantAddX, restaurantAddY, customerAddX, customerAddY);
  taskItems.push_front(taskItem);
}