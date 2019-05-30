//
// Created by �ų��� on 2019-05-04.
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
  // �������еĶ���
  for(int i = 0; i<taskItems.size(); i++) {
	  // ���ص�ǰ��ʱ�������
	if(taskItems.at(i).checkWhetherOutTimeAndReturnOutTimeTaskNo(time)!=-1){
      tempOutput.thisTimeFINEDTaskNO.push_back(
          taskItems.at(i).checkWhetherOutTimeAndReturnOutTimeTaskNo(time));
	}
    if (taskItems.at(i).sendGoodState == false &&
            time - taskItems.at(i).receiveTime == 61) {
          tempOutput.thisTimeOut60TaskNO.push_back(taskItems.at(i).num);
        }
	  // ���ص�ǰ��ɶ�����Ų����������󲻼Ʒ���
	if(taskItems.at(i).ReturnFinishedTaskNo(time)!=-1){
          tempOutput.thisTimeFinishedTaskNO.push_back(taskItems.at(i).ReturnFinishedTaskNo(time));
          if (taskItems.at(i).getProfit() != -50) {
			  tempOutput.thisTimeProfitBesidesFINE += 10;
		  }
		  // ����ɶ���ɾ��������
		  taskItems.erase(taskItems.begin()+i);
		  i -= 1; // �ؼ��������ڱ���������ɾ����Ԫ�أ�����һ��Ҫi-=1
	}
        
  }
  // ���㷣����
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