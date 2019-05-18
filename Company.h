//
// Created by �ų��� on 2019-04-25.
//

#ifndef TAKEAWAYASSIGNMENT0_1_COMPANY_H
#define TAKEAWAYASSIGNMENT0_1_COMPANY_H

#include <string>
#include "Riders.h"

class Company {
 private:
  char *name;
  int x;
  int y;
  int worldTime;
  int totalAsset;

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
};

#endif  // TAKEAWAYASSIGNMENT0_1_COMPANY_H
