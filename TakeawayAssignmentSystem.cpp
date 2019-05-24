#include <iostream>
#include <windows.h>
#include "Company.h"
#include "Screen.h"
#include "SalesList.h"

int main() {
  using namespace std;
  // 0 生成预处理队列对象并自动导入数据
  SalesList originSalesList;
  // 1 生成公司和基础屏幕
  // 1-1 生成默认公司对象
  Company com1 = Company(3, 11, 14);
  // 1-2 运行公司欢迎界面(部分完成)
  com1.welcomeGuide();
  // 1-2 生成默认屏幕对象
  Screen mapScreen(com1,8);
  mapScreen.PrintTheBasicMap();
  
  // 1-3 更改位置用于测试
  com1.riderGroup.riders[1].coordinateOfSelf.changeCoordinate(14, 3);
  com1.riderGroup.riders[2].coordinateOfSelf.changeCoordinate(2, 15);

  // 2 读取SalesList
  int tempRiderNUM = 0;
  while (originSalesList.Saleslist.size() &&
         originSalesList.Saleslist.at(0).time == com1.worldTime) {
    com1.riderGroup.distributeTheTask(tempRiderNUM, originSalesList.Saleslist.at(0).no,
                                      originSalesList.Saleslist.at(0).time,
                                      true,
                                      originSalesList.Saleslist.at(0).restAddX,
                                      originSalesList.Saleslist.at(0).restAddY,
                                      originSalesList.Saleslist.at(0).cusAddX,
                                      originSalesList.Saleslist.at(0).cusAddY);
    originSalesList.Saleslist.pop_front();
	tempRiderNUM += 1;
  }


  // 3 假装分配路线
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
  //getchar();
  // 
  system("pause");
	return 0;
}


