#include "Company.h"
#include "SalesList.h"

void unitTestOfCoordinate();
void unitTestOfTasksItem();
void unitTestOfRoute();
void unitTestOfTasksItemList();
void unitTestOfRider();
void unitTestOfRiders();
void unitTestOfCompany();
void unitTestOfSalesList();
void unitTest();
/*
int main() {
//      unitTestOfCoordinate();
//      unitTestOfTasksItem();
//      unitTestOfRoute();
//      unitTestOfTasksItemList();
//      unitTestOfRider();
//      unitTestOfRiders();
//      unitTestOfCompany();
//	    unitTest();
//      unitTestOfSalesList();
}
*/
void unitTestOfTasksItem() {
  std::cout << "UNIT:TEST:OF:TASKSITEM:\n";
  TasksItem task1 = TasksItem(1, 1, false, 2, 4, 4, 6, 6);
  task1.tellTheTasksItem();
  task1.changeContributionDetail(true, 4);
  task1.changeFetchGoodState(true);
  task1.changeSendDetailAndReturnFinishedTaskNo(true, 8);
  task1.tellTheTasksItem();
  std::cout << "UNIT:TEST:OF:TASKSITEM:END:\n";
}

void unitTestOfCoordinate() {
  std::cout << "UNIT:TEST:OF:COORDINATE:\n";
  Coordinate coordinate1;
  coordinate1.changeCoordinate(3, 5);
  coordinate1.tellPosition();
  coordinate1.move(coordinate1.downStraight);
  coordinate1.tellPosition();
  Coordinate coordinate2;
  coordinate2.changeCoordinate(3, 8);
  if (coordinate1.insideJudgeFromAnother(coordinate2))
    std::cout << "The two coordinates are inside.\n";
  else
    std::cout << "The two coordinates are not inside.\n";
  coordinate2.move(coordinate2.leftDown);
  coordinate2.tellPosition();
  if (coordinate1.insideJudgeFromAnother(coordinate2))
    std::cout << "The two coordinates are inside.\n";
  else
    std::cout << "The two coordinates are not inside.\n";
  Coordinate coordinate3 = Coordinate(2, 2);
  coordinate3.tellPosition();
  coordinate3.move(coordinate3.leftDown);
  coordinate3.tellPosition();
  Coordinate coordinate4 = Coordinate(2, 4);
  coordinate3.moveThourghtheIndsideCoordinate(coordinate4);
  Coordinate coordinate5 = Coordinate(2, 5);
  Coordinate coordinate6 = Coordinate(3, 6);
  coordinate5.moveThourghtheIndsideCoordinate(coordinate6);
  coordinate5.tellPosition();
  std::cout << "UNIT:TEST:OF:COORDINATE:END:\n";
}

void unitTestOfRoute() {
  std::cout << "UNIT:TEST:OF:ROUTE:\n";
  Coordinate coordinate = Coordinate(2, 3);
  Route route1;
  route1.tellTheRoute();
  Route route2 = Route(4);
  route2.tellTheRoute();
  route2.routes.at(0).changeCoordinate(3, 4);
  route2.routes.pop_front();
  route2.tellTheRoute();
  route2.routes.push_back(coordinate);
  route2.tellTheRoute();
  Route route3 = Route(0);
  route3.routes.push_back(coordinate);
  route3.tellTheRoute();
  route3.addFrontCustomCoordinate(2, 3);
  route3.addBackCustomCoordinate(3, 3);
  route3.tellTheRoute();
  std::cout << "UNIT:TEST:OF:ROUTE:END:\n";
}

void unitTestOfTasksItemList() {
  std::cout << "UNIT:TEST:OF:TASKITEMLIST:\n";
  TasksItemList list1;
  TasksItem item = TasksItem();
  list1.taskItems.push_front(item);
  list1.tellTasksItemList();
  TasksItemList list2 = TasksItemList(6);
  list2.tellTasksItemList();
  TasksItemList list3;
  list3.addFrontCustomTasksItem(1, 1, false, 1, 2, 4, 4, 4);
  list3.addFrontCustomTasksItem(2, 1, false, 1, 2, 4, 4, 4);
  list3.addBackCustomTasksItem(3, 1, false, 1, 2, 4, 4, 4);
  list3.tellTasksItemList();
  TasksItem item2 = list3.taskItems.at(2);
  item2.tellTheTasksItem();
  std::cout << "UNIT:TEST:OF:TASKITEMLIST:END:\n";
}

void unitTestOfRider() {
  std::cout << "UNIT:TEST:OF:RIDER:\n";
  Rider rider1 = Rider(0, 8, 7);
  rider1.tellTheRider();
  rider1.moveFromChange(Coordinate::leftStraight);
  rider1.tellTheRider();
  Coordinate tempCoordinate = Coordinate(8, 7);
  rider1.changeCoordinateOfSelf(tempCoordinate);
  rider1.tellTheRider();
  rider1.theRoute.addFrontCustomCoordinate(10, 7);
  rider1.changeCoordinateOfSelfByRoutes();
  rider1.tellTheRider();
  rider1.theTaskList.addFrontCustomTasksItem(0, 1, true, 0, 10, 8, 10, 8);
  rider1.updateMytaskListStateAfterMovement(31);
  rider1.tellTheRider();
  std::cout << "UNIT:TEST:OF:RIDER:END:\n";
}

void unitTestOfRiders() {
  std::cout << "UNIT:TEST:OF:RIDERS:\n";
  Riders ridersGroup1 = Riders(3, 8, 7);
  ridersGroup1.tellAllRidersInfo();
  ridersGroup1.increaseTheRiders(2, 9, 7);
  ridersGroup1.tellAllRidersInfo();
  for (int i = 0; i < ridersGroup1.riders.size(); i++) {
    ridersGroup1.riders[i].theRoute.addFrontCustomCoordinate(6, 7);
    ridersGroup1.riders[i].theTaskList.addFrontCustomTasksItem(0, 1, true, i, 6,
                                                               6, 6, 6);
  }
  ridersGroup1.tellAllRidersInfo();
  ridersGroup1.changeCoordinateOfAllRidersByRoutes();
  ridersGroup1.tellAllRidersInfo();
  ridersGroup1.updateAllRidertaskListStateAfterMovement(30);
  ridersGroup1.tellAllRidersInfo();
  
  ridersGroup1.tellAllRidersInfo();
  std::cout << "theFinalProfit: " << ridersGroup1.getTheFinalProfit() << "$\n";
  Riders riderGroup2;
  riderGroup2.tellAllRidersInfo();
  std::cout << "UNIT:TEST:OF:RIDERS:END:\n";
}

void unitTestOfCompany() {
  std::cout << "UNIT:TEST:OF:COMPANY:\n";
  Company company1;
  company1.printCompanyInfo();
  company1.welcomeGuide();
  company1.printCompanyInfo();
  company1.buyRiders(3);
  company1.printCompanyInfo();
  Company company2 = Company(1, 6, 7);
  company2.buyRiders(2);
  company2.printCompanyInfo();
  std::cout << "UNIT:TEST:OF:COMPANY:END:\n";
}


void unitTest() {
  Company company2 = Company(1, 8, 7);
  company2.buyRiders(2);
  company2.welcomeGuide();
  company2.printCompanyInfo();
  for (int i = 0; i < company2.riderGroup.riders.size(); i++) {
    company2.riderGroup.distributeTheTask(i,i,1,true,6,6,6,6);
  }
  for (int i = 0; i < company2.riderGroup.riders.size(); i++) {
    company2.riderGroup.riders.at(i).theRoute.addBackCustomCoordinate(6, 7);
  }
  company2.runAndUpdateCompany();
  company2.printCompanyInfo();
}

void unitTestOfSalesList(){
  using namespace std;
  
  
  SalesList lists;
  //检查数据合法性
  lists.PrintSalsesList();
  
  //关闭文件输入流
  system("pause");
}