//
// Created by �ų��� on 2019-04-25.
//

#include "Rider.h"

Rider::Rider() {
  id = -1;
  totalProfitGet = 0;
  coordinateOfSelf = Coordinate();
}

Rider::Rider(int id1, int x, int y) {
  id = id1;  // idӦ�ô�����������������,ͨ��id1����
  totalProfitGet = 0;
  coordinateOfSelf = Coordinate(x, y);
  tempbesidesLOC = tempBesidesLOC();
  // �����������ݽṹ����Ĭ�Ϲ�����
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
  // TODO::����·���滮�㷨����
}

int Rider::intimateMyRouteAndReturnIncreasedStepsNum(
    int num1, int receiveTime1, bool contributionState1, int riderId1,
    int restaurantAddX, int restaurantAddY, int customerAddX,
    int customerAddY) {
  // TODO::����·���滮�㷨����,���ñ�����taskItemList�е�ȫ����������������񷵻ز�����������
  int inimatedAllStep = -1;
  // TODO::���㲿��
  //
  return 0;
}

void Rider::updateMytaskListStateAfterMovement(int time) {
	
  for (int i = 0; i < Rider::theTaskList.taskItems.size(); i++) {
    bool fetchchange = false;
    bool sendchange = false;
    if (Rider::coordinateOfSelf.insideJudgeFromAnother(
            theTaskList.taskItems[i].restaurantAdd)) {
      fetchchange = true;
      theTaskList.taskItems[i].changeFetchGoodState(true);
    }
    if (Rider::coordinateOfSelf.insideJudgeFromAnother(
            theTaskList.taskItems[i].customerAdd) &&
        theTaskList.taskItems[i].fetchGoodState) {
      sendchange = true;
      theTaskList.taskItems[i].changeSendDetailAndReturnFinishedTaskNo(true, time);
    }
	if (sendchange && fetchchange) {
      if ((theTaskList.taskItems[i].customerAdd.returnTheXPosition() ==
               theTaskList.taskItems[i].restaurantAdd.returnTheXPosition()) &&
              (theTaskList.taskItems[i].customerAdd.returnTheYPosition() ==
               theTaskList.taskItems[i].restaurantAdd.returnTheYPosition())){
            tempbesidesLOC.pushLOC(
                tempBesidesLOC::resANDcus,
                theTaskList.taskItems[i].customerAdd.returnTheXPosition(),
                theTaskList.taskItems[i].customerAdd.returnTheYPosition());
      } else {
        tempbesidesLOC.pushLOC(
            tempBesidesLOC::customer,
            theTaskList.taskItems[i].customerAdd.returnTheXPosition(),
            theTaskList.taskItems[i].customerAdd.returnTheYPosition());
        tempbesidesLOC.pushLOC(
            tempBesidesLOC::resruant,
            theTaskList.taskItems[i].restaurantAdd.returnTheXPosition(),
            theTaskList.taskItems[i].restaurantAdd.returnTheYPosition());
	  }
      
	  continue;
	}
    if (sendchange == true && fetchchange == false) {
          tempbesidesLOC.pushLOC(
          tempBesidesLOC::customer,
              theTaskList.taskItems[i].customerAdd.returnTheXPosition(),
              theTaskList.taskItems[i].customerAdd.returnTheYPosition());
      continue;
    }
    if (sendchange == false && fetchchange == true) {
      tempbesidesLOC.pushLOC(
          tempBesidesLOC::resruant,
          theTaskList.taskItems[i].restaurantAdd.returnTheXPosition(),
          theTaskList.taskItems[i].restaurantAdd.returnTheYPosition());
      continue;
    }
  }
}

void Rider::outPutThisTimeANDresetTempBesidesLOC() {
	using namespace std;
  ofstream outfile;
  outfile.open("output.txt", ios::app);
  outfile << "����"<< id << "λ�ã�" << coordinateOfSelf.returnTheXPosition() << "��"
          << coordinateOfSelf.returnTheYPosition() << "��ͣ����";
  if(!tempbesidesLOC.restrantLOC.empty()) {
    outfile << "�͹� ";
	  for(auto i:tempbesidesLOC.restrantLOC){
      outfile << i.x << " " << i.y << " ";
	  }
  }
  if (!tempbesidesLOC.customerLOC.empty()) {
    outfile << "ʳ�� ";
    for (auto i : tempbesidesLOC.customerLOC) {
      outfile << i.x << " " << i.y << " ";
    }
  }
  if (!tempbesidesLOC.resANDcusLOC.empty()) {
    outfile << "�Ϳ� ";
    for (auto i : tempbesidesLOC.resANDcusLOC) {
      outfile << i.x << " " << i.y << " ";
    }
  }
  outfile << "��" << endl;
  outfile.close();
  tempbesidesLOC.resetMe();
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

int Rider::getTheTotalProfit() { return totalProfitGet; }
