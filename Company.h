//
// Created by 张成敏 on 2019-04-25.
//

#ifndef TAKEAWAYASSIGNMENT0_1_COMPANY_H
#define TAKEAWAYASSIGNMENT0_1_COMPANY_H

#include <string>
#include "Riders.h"
#include <fstream>
#include <assert.h>
#include "OutputDataOfthisTime.h"
#define FITLIMIT 60

class Company {
 public:
  char *name;
  int x;
  int y;
  int receiveTaskNum;
  int finishedTaskNum;
  int outTimeTaskNum;
  int worldTime;
  int totalAsset;
  OutputDataOfthisTime outputThisTime;
 public:
  Riders riderGroup;
  Company();
  explicit Company(int riderNum, int x1, int y1);
  void changeTheCompanyName(char *newName);
  bool buyRiders(int num);
  void welcomeGuide();
  void runAndUpdateCompany();
  void UpdateCompanyInFirstTime();
  // 分配任务并在无法分配建议购买骑手时返回数值正整数，无须购买时返回0
  void  receiveDistributeTheTask(int no, int time0, int restaurantAddX,
                                int restaurantAddY, int customerAddX,
                                int customerAddY);
  void printCompanyInfo();
  void printPartCompanyInfo();
  void gotoxy(int x,int y);
};

#endif  // TAKEAWAYASSIGNMENT0_1_COMPANY_H
