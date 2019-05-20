//
// Created by 张成敏 on 2019-04-25.
//

#include "Company.h"

Company::Company() {
  totalAsset = 1000;
  x = 8;
  y = 7;
  receiveTaskNum = 0;
  finishedTaskNum = 0;
  outTimeTaskNum = 0;
  worldTime = 0;  //执行完欢迎使用引导后世界时间变成1
  name = new char[100];
  riderGroup = Riders(0, 8, 7);
  strcpy_s(name, 100,"defaultName");
}

Company::Company(int riderNum, int x1, int y1) {
  totalAsset = 1000;
  worldTime = 0;
  receiveTaskNum = 0;
  finishedTaskNum = 0;
  outTimeTaskNum = 0;
  x = x1;
  y = y1;
  name = new char[100];
  Coordinate checkCoordinate = Coordinate(x, y);
  if (1000 - riderNum * 300 < 0) {
    riderNum = 0;
  }
  if (checkCoordinate.roadJudge()) {
    riderGroup = Riders(riderNum, x, y);
    totalAsset -= riderNum * 300;
    strcpy_s(name, 100, "defaultName");
  } else {
    riderGroup = Riders(riderNum, 8, 7);
    totalAsset -= riderNum * 300;
    strcpy_s(name, 100, "defaultName");
  }
}

bool Company::buyRiders(int num) {
  if (totalAsset - num * 300) {
    riderGroup.increaseTheRiders(num, x, y);
    totalAsset -= num * 300;
    return true;
  }
  return false;
}

void Company::changeTheCompanyName(char *newName) {
  strcpy_s(name, 100, newName);
}

int Company::receiveDistributeTheTask(int no, int time, int restaurantAddX,
                                       int restaurantAddY, int customerAddX,
                                       int customerAddY) {
  // TODO:: 订单分配核心算法
  // 分配任务并在无法分配建议购买骑手时返回数值正整数，无须购买时返回0
  int buyRidersJudgeNum = 0;
  int distributeRiderNo = -1;
  // TODO:: 经过匹配度计算计算出匹配骑手若需要购买骑手请先返回购买数量不执行分配语句
  if (!buyRidersJudgeNum) {
    riderGroup.distributeTheTask(distributeRiderNo, no, time, true,
                                 restaurantAddX, restaurantAddY, customerAddX,
                                 customerAddY);
    receiveTaskNum += 1;
  }
  
  return buyRidersJudgeNum;
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
  //	receiveDistributeTheTask
  //    updatetheRouteOfAllRiders();
  //    changeCoordinateOfAllRidersByRoutes();
  //    updateAllRidertaskListStateAfterMovement(time);
  worldTime += 1;
  // TODO::同时返回完成单数与超时单数
  totalAsset += riderGroup.allRidersActionLoopAndReturnProfit(worldTime);
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

void Company::printPartCompanyInfo() { 
	std::cout << "Company   Name: " << name << "\n";
	std::cout << "Company Assets: " << totalAsset << " $\n";
    std::cout << "All World Time: " << worldTime << "\n";
    std::cout << "Receive TasksN: " << receiveTaskNum << "\n";
    std::cout << "Finished TaskN: " << finishedTaskNum << "\n";
}
