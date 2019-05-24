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
  com1.riderGroup.riders[1].coordinateOfSelf.changeCoordinate(14, 3);
  com1.riderGroup.riders[2].coordinateOfSelf.changeCoordinate(2, 15);
  // 1-2 运行公司欢迎界面(部分完成)
  com1.welcomeGuide();
  // 1-2 生成默认屏幕对象
  Screen mapScreen(com1,8);
  mapScreen.PrintTheBasicMap();
  
  // 1-3 更改位置用于测试
  

  // 2 读取SalesList并进行订单分配
  



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

  // 打印第1时刻出生时刻位置
  mapScreen.PrintChangableElem();
  mapScreen.PrintChangableWords();
  
  
  // 4 运行公司根据指派订单与计算的线路
  for(int i = 0;i<5;i++) {
    
	// 4-1 分配该时刻的订单(暂时为虚假分配)
	int tempRiderNUM = 0;
    while (originSalesList.Saleslist.size() &&
           originSalesList.Saleslist.at(0).time == com1.worldTime) {

      com1.riderGroup.distributeTheTask( tempRiderNUM, originSalesList.Saleslist.at(0).no,
          originSalesList.Saleslist.at(0).time, true,
          originSalesList.Saleslist.at(0).restAddX,
          originSalesList.Saleslist.at(0).restAddY,
          originSalesList.Saleslist.at(0).cusAddX,
          originSalesList.Saleslist.at(0).cusAddY);

      originSalesList.Saleslist.pop_front();

      tempRiderNUM += 1;
    }
    // 4-2 根据screen对象中所存的上一秒信息清理屏幕
    Sleep(1000);
    mapScreen.ClearChangableElem();
	// 4-3 运行公司并更新其中thistime数据
    com1.runAndUpdateCompany();
	// 时间运行之后
	// 4-4 重新加载屏幕数据
    mapScreen.ReloadTheScreenData(com1);
    // 4-5 根据重新加载的屏幕数据进行打印活动对象
    mapScreen.PrintChangableElem();
	mapScreen.PrintChangableWords();
	// 4-6 重置公司内thistime数据
    com1.outputThisTime.resetMe(); // 屏幕对象获取当前公司在输出对象后，reset这一对象
  }
 

  //
  //getchar();
  // 
  system("pause");
	return 0;

}


