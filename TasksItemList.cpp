//
// Created by 张成敏 on 2019-05-04.
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

OutputDataOfthisTime TasksItemList::returnOutputDataOfthisTimeAndPopFinishedTasks(int time) {
  OutputDataOfthisTime tempOutput;
  // 遍历所有的订单
  for(int i = 0; i<taskItems.size(); i++) {
	  // 返回超时订单编号
	if(taskItems.at(i).checkWhetherOutTimeAndReturnOutTimeTaskNo(time)!=-1){
      tempOutput.thisTimeFINEDTaskNO.push_back(
          taskItems.at(i).checkWhetherOutTimeAndReturnOutTimeTaskNo(time));
	}
	  // 返回完成订单编号
        
  }
  return tempOutput;
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