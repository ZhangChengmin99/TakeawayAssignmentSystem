//
// Created by �ų��� on 2019-04-25.
//

#include "Company.h"

Company::Company() {
  totalAsset = 1000;
  worldTime = 0;  //ִ���껶ӭʹ������������ʱ����1
  name = new char[100];
  riderGroup = Riders(0, 8, 7);
  strcpy(name, "defaultName");
}

Company::Company(int riderNum, int x, int y) {
  totalAsset = 1000;
  worldTime = 0;
  name = new char[100];
  Coordinate checkCoordinate = Coordinate(x, y);
  if (1000 - riderNum * 300 < 0) {
    riderNum = 0;
  }
  if (checkCoordinate.roadJudge()) {
    riderGroup = Riders(riderNum, x, y);
    totalAsset -= riderNum * 300;
    strcpy(name, "defaultName");
  } else {
    riderGroup = Riders(riderNum, 8, 7);
    totalAsset -= riderNum * 300;
    strcpy(name, "defaultName");
  }
}

bool Company::buyRiders(int num) {
  if (totalAsset - num * 300) {
    riderGroup.increaseTheRiders(num, 8, 7);
    totalAsset -= num * 300;
    return true;
  }
  return false;
}

void Company::changeTheCompanyName(char *newName) { strcpy(name, newName); }

bool Company::receiveDistributeTheTask(int no, int time, int restaurantAddX,
                                       int restaurantAddY, int customerAddX,
                                       int customerAddY) {
  // TODO:: ������������㷨
  int distributeRiderNo = -1;
  // TODO:: ����ƥ��ȼ�������ƥ������
  return riderGroup.distributeTheTask(distributeRiderNo, no, time, true,
                                      restaurantAddX, restaurantAddY,
                                      customerAddX, customerAddY);
}

void Company::welcomeGuide() {
  std::cout << "WELCOME TO TAKEAWAY ASSIGNMENT SYSTEM!\n";
  std::cout << "In the beginning, let's name our company!\n";
  std::cout << "Please enter the name: ";
  char *newName = new char[100];
  std::cin >> newName;
  Company::changeTheCompanyName(newName);
  std::cout << "GREAT! YOUR COMPANY: " << name << " SET UP!\n";
  worldTime += 1;
}

void Company::runAndUpdateCompany() {
  // ִ��receiveDistributeTheTask��Ĳ���
  //    updatetheRouteOfAllRiders();
  //    changeCoordinateOfAllRidersByRoutes();
  //    updateAllRidertaskListStateAfterMovement(time);
  riderGroup.allRidersActionLoop(worldTime);
  // ���
  worldTime += 1;
}

void Company::printCompanyInfo() {
  std::cout << "*************************************************************"
               "********\n";
  std::cout << "The Company Info:\n";
  std::cout << "The Name of the Company: " << name << '\n';
  std::cout << "The Asset of the Company: " << totalAsset << '\n';
  std::cout << "The WordTime of the Company: " << worldTime << '\n';
  std::cout << "The Number of Riders: " << riderGroup.riders.size() << '\n';
  riderGroup.tellAllRidersInfo();
  std::cout << "*************************************************************"
               "********\n";
}