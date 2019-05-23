//
// Created by 张成敏 on 2019-05-04.
//

#ifndef TAKEAWAYASSIGNMENT0_1_TASKSITEMLIST_H
#define TAKEAWAYASSIGNMENT0_1_TASKSITEMLIST_H

#include <deque>
#include "TasksItem.h"
#include "OutputDataOfthisTime.h"

class TasksItemList {
 public:
  std::deque<TasksItem> taskItems;
  // 生成空队列
  TasksItemList();
  // 生成num数量成员的队列
  explicit TasksItemList(int num);
  // 返回完成的任务收益并且将此任务出队列
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
