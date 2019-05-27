//
// Created by �ų��� on 2019-04-25.
//

#include "Company.h"
#include <iomanip>
#include <Windows.h>


Company::Company() {
  totalAsset = 1000;
  x = 8;
  y = 7;
  receiveTaskNum = 0;
  finishedTaskNum = 0;
  outTimeTaskNum = 0;
  worldTime = 0;  //ִ���껶ӭʹ������������ʱ����1
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


  // TODO:: ������������㷨
void Company::receiveDistributeTheTask(int no, int time0, int restaurantAddX,
                                        int restaurantAddY, int customerAddX,
                                        int customerAddY) {
    // TODO:: ������������㷨
    // �����������޷����佨�鹺������ʱ������ֵ�����������빺��ʱ����0
    int buyRidersJudgeNum = 0;
    int distributeRiderNo = -1;
    int riderNumber = (int)riderGroup.riders.size();
    // TODO:: ������������㷨
    if (riderNumber == 1)  //������ֻ��һ���˵�ʱ��
    {
      distributeRiderNo = 0;
    } else {
      std::deque<int> fitness;
      std::deque<int> fitnessCopy;
      std::deque<int> fitnessSorted;
      std::deque<int> time;
      fitness.clear();
      fitnessCopy.clear();
      fitnessSorted.clear();
      time.clear();
      int distance1 = 0, distance2 = 0, distance3 = 0, time1 = 0,
          mindistance = 0, time2 = 0;
      double distanceBetweenRiders = 0;
      for (int i = 0; i < riderNumber; i++, distanceBetweenRiders = 0) {
        // distance1�������ֵ�ǰλ����͹ݵľ���
        distance1 = riderGroup.stepDistance(
            riderGroup.riders.at(i).coordinateOfSelf.returnTheXPosition(),
            riderGroup.riders.at(i).coordinateOfSelf.returnTheYPosition(),
            restaurantAddX, restaurantAddY);
        for (int j = 1, minloc = 0,
                 mindistance =
                     riderGroup.stepDistance(riderGroup.riders.at(i)
                                                 .theRoute.routes.at(0)
                                                 .returnTheXPosition(),
                                             riderGroup.riders.at(i)
                                                 .theRoute.routes.at(0)
                                                 .returnTheYPosition(),
                                             customerAddX, customerAddY);
             j < (int)riderGroup.riders.at(i).theRoute.routes.size(); j++) {
          if (riderGroup.stepDistance(riderGroup.riders.at(i)
                                          .theRoute.routes.at(j)
                                          .returnTheXPosition(),
                                      riderGroup.riders.at(i)
                                          .theRoute.routes.at(j)
                                          .returnTheYPosition(),
                                      customerAddX,
                                      customerAddY) < mindistance) {
            minloc = j;
            mindistance = riderGroup.stepDistance(riderGroup.riders.at(i)
                                                      .theRoute.routes.at(j)
                                                      .returnTheXPosition(),
                                                  riderGroup.riders.at(i)
                                                      .theRoute.routes.at(j)
                                                      .returnTheYPosition(),
                                                  customerAddX, customerAddY);
          }
        }
        distance2 = mindistance;  // distance2�������ֵ�·���о���ͻ�����ľ���
        for (int k = 0; k < riderNumber; k++) {
          distanceBetweenRiders += sqrt(
              pow(riderGroup.riders.at(k).coordinateOfSelf.returnTheXPosition(),
                  2) +
              pow(riderGroup.riders.at(k).coordinateOfSelf.returnTheYPosition(),
                  2));
        }
        distance3 = (int)distanceBetweenRiders /
                    riderNumber;  // distance3��������֮��ľ��룬�����ܶ�
        time1 = (int)riderGroup.riders.at(i)
                    .theRoute.routes.size();  // time1�����������е�����������ʱ��
        time2 =
            riderGroup.riders.at(i)
                .intimateMyRouteAndReturnIncreasedStepsNum(no,time0,true,i,restaurantAddX,restaurantAddY,customerAddX,customerAddY);  // time2�������������ɵ����ӵ�ʱ��
        fitness.push_back(distance1 + distance2 + time1 + 2 * time2 +
                          distance3);  //����ƥ��ȣ�ƥ���ԽСԽ�ʺϱ��ɵ���
        time.push_back(time1 + time2);  //������ʱ��
      }
      fitnessCopy = fitness;
      for (int i = 1, minfitness = fitness.at(0), minfitnessloc = 0;
           i < (int)fitness.size();
           i++)  //��ƥ��Ƚ������򣬽���Ӧ���ֵı����fitnessSorted�洢
      {
        if (fitness.at(i) < minfitness && fitness.at(i) != -1) {
          minfitness = fitness.at(i);
          minfitnessloc = i;
        }
        if (minfitness < FITLIMIT) {
          buyRidersJudgeNum = 1;
        }
        fitnessSorted.push_back(minfitnessloc);
        fitness.erase(fitness.begin() + minfitnessloc);
        fitness.insert(fitness.begin() + minfitnessloc, -1);
      }
      for (int i = 0; i < riderNumber; i++) {
        if (time.at(fitnessSorted.at(i)) <
            30)  //����������30��λʱ�����굥���ɵ��������֣������ɸ���һλ����
        {
          distributeRiderNo = fitnessSorted.at(i);
        }
      }
      if (distributeRiderNo == -1)  //�����������ɵ����ᳬʱʱ
      {
        for (int i = 0; i < riderNumber; i++) {
          if (time.at(fitnessSorted.at(i)) <
              60)  //ѡ�񲻻ᳬ��60��λʱ��������ɵ�
          {
            distributeRiderNo = fitnessSorted.at(i);
          }
        }
      }
    }
    // TODO::
    // ����ƥ��ȼ�������ƥ����������Ҫ�����������ȷ��ع���������ִ�з������
    if (!buyRidersJudgeNum) {
      riderGroup.distributeTheTask(distributeRiderNo, no, time0, true,
                                   restaurantAddX, restaurantAddY, customerAddX,
                                   customerAddY);

      //
      receiveTaskNum += 1;
    } else {
      if (buyRiders(1)) {
        riderGroup.distributeTheTask((int)riderGroup.riders.size() - 1, no, time0,
                                     true, restaurantAddX, restaurantAddY,
                                     customerAddX, customerAddY);
      } else {
        riderGroup.distributeTheTask(distributeRiderNo, no, time0, true,
                                     restaurantAddX, restaurantAddY,
                                     customerAddX, customerAddY);
      }
    }
  }
    

void Company::welcomeGuide() {
	using namespace std;
  SetConsoleTitle(L"TakeawayAssignmentSystem 1.0 by Group 22");
  std::cout << "\n "
               "***************************************************************"
               "***************************************************\n";
  
  cout << " *                                                                  "
          "                                              *\n";
  std::cout << " *                                    WELCOME TO TAKEAWAY ASSIGNMENT SYSTEM 1.0!                                  *\n";
  std::cout << " *                                         Firstly , let's name our company!                                      *\n";
  std::cout << " *                                         Please enter the name:                                                 *\n";
  
  std::cout << " *                                                                                                                *\n";
  cout << " *                                                                  "
          "                                              *\n";
  std::cout << " "
               "***************************************************************"
               "***************************************************";
  
  gotoxy(66, 5);

  char *newName = new char[100];
  std::cin >> newName;
  Company::changeTheCompanyName(newName);
  // ��ӡ�����ɹ����
  Sleep(500);
  gotoxy(39, 6);
  cout << "GREAT ! YOUR COMPANY : " << left << setw(10) << name << " SET UP!";
  // ���ش�ӡλ��
  gotoxy(0,8);
  worldTime += 1;
  Sleep(1000);
}

void Company::runAndUpdateCompany() {
  //	receiveDistributeTheTask
  //    updatetheRouteOfAllRiders();
  //    changeCoordinateOfAllRidersByRoutes();
  //    updateAllRidertaskListStateAfterMovement(time);
  worldTime += 1;
  // TODO::ͬʱ������ɵ����볬ʱ����

  outputThisTime = riderGroup.allRidersActionLoopAndReturnProfit(worldTime);
  
  finishedTaskNum += outputThisTime.thisTimeFinishedTaskNO.size();
  outTimeTaskNum += outputThisTime.thisTimeFINEDTaskNO.size();
  totalAsset += outputThisTime.thisTimeProfitBesidesFINE - outputThisTime.thisTimeFINE;

  
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
	using namespace std;
	cout << "\n "
          "********************************************************************"
          "**********************************************\n";
  cout << " *                                                                  "
          "                                              *\n";
	std::cout << " *   Company   Name: " << std::setw(10) << name;
  std::cout << "                                                                                  *\n";
    std::cout << " *   Company Assets: " << std::setw(8) << totalAsset << " $";
  std::cout << "                                                               "
               "                    *\n";
        std::cout << " *   All World Time: " << std::setw(10) << worldTime;
  std::cout << "                                                               "
               "                    *\n";
        std::cout << " *   Receive TasksN: " << std::setw(10) << receiveTaskNum;
  std::cout << "                                                               "
               "                    *\n";
        std::cout << " *   Finished TaskN: " << std::setw(10) << finishedTaskNum;
  std::cout << "                                                               "
               "                    *\n";
        cout << " *                                                            "
                "      "
                "                                              *\n";
        cout << " "
                "**************************************************************"
                "******"
                "**********************************************\n";
}

void Company::gotoxy(int x, int y) {
  COORD pos = {x, y};
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ��׼����豸���
  SetConsoleCursorPosition(hOut, pos);  //���������ֱ���ָ���ĸ����壬����λ��
}
