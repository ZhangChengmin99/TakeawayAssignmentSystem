//
// Created by 张成敏 on 2019-05-03.
//

#ifndef TAKEAWAYASSIGNMENT0_1_TASKSITEM_H
#define TAKEAWAYASSIGNMENT0_1_TASKSITEM_H

#include <iostream>
#include "Coordinate.h"

class TasksItem {
public:
  int num;
  int receiveTime;
  bool contributionState;
  int riderId;
  bool fetchGoodState;
  bool sendGoodState;
  int arrivedTime;
  int profit;

 public:
  Coordinate restaurantAdd;
  Coordinate customerAdd;
  TasksItem();
  explicit TasksItem(int num1, int receiveTime1, bool contributionState1,
                    int riderId1,
            int restaurantAddX, int restaurantAddY, int customerAddX,
            int customerAddY);
  void changeContributionDetail(bool state, int riderId1);
  void changeFetchGoodState(bool state);
  
  int changeSendDetailAndReturnFinishedTaskNo(bool state, int arrivedTime1);
  // 如果完成返回订单编号
  int ReturnFinishedTaskNo(int worldTime);
  // 如果超时返回订单编号
  int checkWhetherOutTimeAndReturnOutTimeTaskNo(int worldTime);
  int getProfit();
  void tellTheTasksItem();
};

#endif  // TAKEAWAYASSIGNMENT0_1_TASKSITEM_H
