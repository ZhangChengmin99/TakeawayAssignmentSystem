//
// Created by 张成敏 on 2019-04-25.
//

#include "Rider.h"

Rider::Rider() {
  id = -1;
  totalProfitGet = 0;
  coordinateOfSelf = Coordinate();
}

Rider::Rider(int id1, int x, int y) {
  id = id1;  // id应该从总骑手数组中引用,通过id1传入
  totalProfitGet = 0;
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

int Rider::intimateMyRouteAndReturnIncreasedStepsNum(
    int num1, int receiveTime1, bool contributionState1, int riderId1,
    int restaurantAddX, int restaurantAddY, int customerAddX,
    int customerAddY) {
  // TODO::个人路径规划算法核心,利用本骑手taskItemList中的全部任务外加输入任务返回步数增加数量
  int inimatedAllStep = -1;
  // TODO::计算部分
  //
  return inimatedAllStep - theRoute.routes.size();
}

void Rider::updateMytaskListStateAfterMovement(int time) {
  for (int i = 0; i < Rider::theTaskList.taskItems.size(); i++) {
    if (Rider::coordinateOfSelf.insideJudgeFromAnother(
            theTaskList.taskItems[i].restaurantAdd)) {
      theTaskList.taskItems[i].changeFetchGoodState(true);
    }
    if (Rider::coordinateOfSelf.insideJudgeFromAnother(
            theTaskList.taskItems[i].customerAdd) &&
        theTaskList.taskItems[i].fetchGoodState) {
      theTaskList.taskItems[i].changeSendDetailAndReturnFinishedTaskNo(true, time);
    }
  }
}

OutputDataOfthisTime Rider::returnOutputDataOfthisTimeAndPopFinishedTasks(int time) {
  OutputDataOfthisTime tempOutput;
  tempOutput.increaseMySelfFromAnotherOutput(theTaskList.returnOutputDataOfthisTimeAndPopFinishedTasks(time));
  totalProfitGet += tempOutput.thisTimeProfitBesidesFINE - tempOutput.thisTimeFINE;
  return tempOutput;
}

void Rider::tellTheRider() {
  std::cout << "**********************************************\n";
  std::cout << "1.The id:" << Rider::id << " rider data:\n";
  std::cout << "2.The position of self:\n";
  Rider::coordinateOfSelf.tellPosition();
  std::cout << "3.The Routes of the future:\n";
  Rider::theRoute.tellTheRoute();
  std::cout << "4.The TaskList:\n";
  Rider::theTaskList.tellTasksItemList();
  std::cout << "5.The Total Profit Gets: " << totalProfitGet << "$\n";
  std::cout << "**********************************************\n";
}

char* Rider::outputThisTime() { 
	char *output;
	output = new char[100];
	std::cout << "骑手" << id ;
	return nullptr; }

int Rider::getTheTotalProfit() { return totalProfitGet; }
