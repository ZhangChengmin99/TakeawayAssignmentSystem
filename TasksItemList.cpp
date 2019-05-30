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
	  // 返回当前超时订单编号
	if(taskItems.at(i).checkWhetherOutTimeAndReturnOutTimeTaskNo(time)!=-1){
      tempOutput.thisTimeFINEDTaskNO.push_back(
          taskItems.at(i).checkWhetherOutTimeAndReturnOutTimeTaskNo(time));
	}
    if (taskItems.at(i).sendGoodState == false &&
            time - taskItems.at(i).receiveTime == 61) {
          tempOutput.thisTimeOut60TaskNO.push_back(taskItems.at(i).num);
        }
	  // 返回当前完成订单编号并计算获得利润不计罚款
	if(taskItems.at(i).ReturnFinishedTaskNo(time)!=-1){
          tempOutput.thisTimeFinishedTaskNO.push_back(taskItems.at(i).ReturnFinishedTaskNo(time));
          if (taskItems.at(i).getProfit() != -50) {
			  tempOutput.thisTimeProfitBesidesFINE += 10;
		  }
		  // 将完成订单删除出队列
		  taskItems.erase(taskItems.begin()+i);
		  i -= 1; // 关键：由于在遍历过程中删除了元素，所以一定要i-=1
	}
        
  }
  // 计算罚款金额
  tempOutput.thisTimeFINE = (tempOutput.thisTimeFINEDTaskNO.size())*50;
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