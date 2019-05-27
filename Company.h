//
// Created by �ų��� on 2019-04-25.
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
  // �����������޷����佨�鹺������ʱ������ֵ�����������빺��ʱ����0
  void  receiveDistributeTheTask(int no, int time0, int restaurantAddX,
                                int restaurantAddY, int customerAddX,
                                int customerAddY);
  void printCompanyInfo();
  void printPartCompanyInfo();
  void gotoxy(int x,int y);
};

#endif  // TAKEAWAYASSIGNMENT0_1_COMPANY_H
