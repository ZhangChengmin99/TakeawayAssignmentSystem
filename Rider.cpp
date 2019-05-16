//
// Created by 张成敏 on 2019-04-25.
//

#include "Rider.h"

Rider::Rider() {
  id = -1;
  theActiveTaskNum = -1;
  coordinateOfSelf = Coordinate();
}

Rider::Rider(int id1, int x, int y) {
  id = id1;  // id应该从总骑手数组中引用,通过id1传入
  theActiveTaskNum = 0;
  coordinateOfSelf = Coordinate(x, y);
  // 其余三个数据结构调用默认构造器
}

bool Rider::changeCoordinateOfSelfByRoutes() {
  if (theRoute.routes.empty()) {
    return false;
  }
  Coordinate tempCoordinate = Rider::theRoute.routes.at(0);
  Rider::theRoute.routes.pop_front();
  return Rider::changeCoordinateOfSelf(tempCoordinate);
}

bool Rider::changeCoordinateOfSelf(Coordinate outCoordinate) {
  return Rider::coordinateOfSelf.moveThourghtheIndsideCoordinate(outCoordinate);
}

bool Rider::moveFromChange(Coordinate::change change1) {
  return Rider::coordinateOfSelf.move(change1);
}

void Rider::updateMytheRoute() {
  // TODO::个人路径规划算法核心
}

void Rider::updateMytaskListStateAfterMovement(int time) {
  for (int i = theActiveTaskNum; i < Rider::theTaskList.taskItems.size(); i++) {
    if (Rider::coordinateOfSelf.insideJudgeFromAnother(
            theTaskList.taskItems[i].restaurantAdd)) {
      theTaskList.taskItems[i].changeFetchGoodState(true);
    }
    if (Rider::coordinateOfSelf.insideJudgeFromAnother(
            theTaskList.taskItems[i].customerAdd)) {
      theTaskList.taskItems[i].changeSendDetail(true, time);
      theActiveTaskNum += 1;
    }
  }
}

void Rider::tellTheRider() {
  std::cout << "**********************************************\n";
  std::cout << "1.The id:" << Rider::id << " rider data:\n";
  std::cout << "2.TheActiveTaskNum:" << Rider::theActiveTaskNum << '\n';
  std::cout << "3.The position of self:\n";
  Rider::coordinateOfSelf.tellPosition();
  std::cout << "4.The Routes of the future:\n";
  Rider::theRoute.tellTheRoute();
  std::cout << "5.The TaskList:\n";
  Rider::theTaskList.tellTasksItemList();
  std::cout << "6.The Total Profit Gets: " << getTheTotalProfit() << "$\n";
  std::cout << "**********************************************\n";
}

int Rider::getTheTotalProfit() {
  int total = 0;
  for (int i = 0; i < Rider::theActiveTaskNum; i++)
    total += theTaskList.taskItems[i].getProfit();
  return total;
}
