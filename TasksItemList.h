//
// Created by �ų��� on 2019-05-04.
//

#ifndef TAKEAWAYASSIGNMENT0_1_TASKSITEMLIST_H
#define TAKEAWAYASSIGNMENT0_1_TASKSITEMLIST_H

#include <deque>
#include "TasksItem.h"
#include "OutputDataOfthisTime.h"

class TasksItemList {
 public:
  std::deque<TasksItem> taskItems;
  // ���ɿն���
  TasksItemList();
  // ����num������Ա�Ķ���
  explicit TasksItemList(int num);
  // ������ɵ��������沢�ҽ������������
  OutputDataOfthisTime returnOutputDataOfthisTimeAndPopFinishedTasks(int time);
  void tellTasksItemList();
  void addFrontCustomTasksItem(int num1, int receiveTime1,
                               bool contributionState1, int riderId1,
                               int restaurantAddX, int restaurantAddY,
                               int customerAddX, int customerAddY);
  void addBackCustomTasksItem(int num1, int receiveTime1,
                              bool contributionState1, int riderId1,
                              int restaurantAddX, int restaurantAddY,
                              int customerAddX, int customerAddY);
};

#endif  // TAKEAWAYASSIGNMENT0_1_TASKSITEMLIST_H
