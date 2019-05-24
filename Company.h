//
// Created by �ų��� on 2019-04-25.
//

#ifndef TAKEAWAYASSIGNMENT0_1_COMPANY_H
#define TAKEAWAYASSIGNMENT0_1_COMPANY_H

#include <string>
#include "Riders.h"
#include "OutputDataOfthisTime.h"

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
  // �����������޷����佨�鹺������ʱ������ֵ�����������빺��ʱ����0
  int  receiveDistributeTheTask(int no, int time, int restaurantAddX,
                                int restaurantAddY, int customerAddX,
                                int customerAddY);
  void printCompanyInfo();
  void printPartCompanyInfo();
  void gotoxy(int x,int y);
};

#endif  // TAKEAWAYASSIGNMENT0_1_COMPANY_H
