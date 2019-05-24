#include <iostream>
#include <windows.h>
#include "Company.h"
#include "Screen.h"

int main() {
  using namespace std;
  // 1 生成公司和基础屏幕
  // 1-1 生成默认公司对象
  Company com1 = Company(3, 11, 14);
  // 1-2 运行公司欢迎界面
  com1.welcomeGuide();
  // 1-2 生成默认屏幕对象
  Screen mapScreen(com1,4);
  mapScreen.PrintTheBasicMap();
  

  com1.riderGroup.riders[1].coordinateOfSelf.changeCoordinate(14, 3);
  com1.riderGroup.riders[2].coordinateOfSelf.changeCoordinate(2, 15);
  // 2 假装分派订单
  com1.riderGroup.distributeTheTask(0, 12, 1, true, 12, 8, 10, 6);
  com1.riderGroup.distributeTheTask(1, 13, 1, true, 12, 2, 10, 2);
  // 3 假装给个路线
  com1.riderGroup.riders.at(1).theRoute.addBackCustomCoordinate(12, 3);
  com1.riderGroup.riders.at(1).theRoute.addBackCustomCoordinate(12, 3);
  com1.riderGroup.riders.at(1).theRoute.addBackCustomCoordinate(12, 3);
  com1.riderGroup.riders.at(1).theRoute.addBackCustomCoordinate(10, 3);
  com1.riderGroup.riders.at(1).theRoute.addBackCustomCoordinate(10, 3);
  //
  com1.riderGroup.riders.at(0).theRoute.addBackCustomCoordinate(11, 12);
  com1.riderGroup.riders.at(0).theRoute.addBackCustomCoordinate(11, 10);
  com1.riderGroup.riders.at(0).theRoute.addBackCustomCoordinate(11, 8);
  com1.riderGroup.riders.at(0).theRoute.addBackCustomCoordinate(11, 6);
  //
  com1.riderGroup.riders.at(0).theRoute.addBackCustomCoordinate(11, 4);
  //
  

  // 4 运行公司根据指派订单与计算的线路
  for(int i = 0;i<5;i++){
    mapScreen.ReloadTheScreenData(com1);
    mapScreen.PrintChangableElem();
	mapScreen.PrintChangableWords();
    //
	com1.runAndUpdateCompany();
    Sleep(1000);
	mapScreen.ClearChangableElem();
  }
  mapScreen.ReloadTheScreenData(com1);
  mapScreen.PrintChangableElem();
  mapScreen.PrintChangableWords();
  //
  
  // 
  system("pause");
	return 0;
}


