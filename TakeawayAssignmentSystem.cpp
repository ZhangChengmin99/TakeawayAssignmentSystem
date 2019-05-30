#include <iostream>
#include <windows.h>
#include "Company.h"
#include "Screen.h"
#include "SalesList.h"

int main() {

  using namespace std;
  // 0 清空上一次的文件内容
  ofstream outfile;
  outfile.open("output.txt", ios::out);
  outfile.close();
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

  // 1-3 假装分配路线
  com1.riderGroup.riders.at(1).theRoute.addBackCustomCoordinate(12, 3);
  com1.riderGroup.riders.at(1).theRoute.addBackCustomCoordinate(12, 3);
  com1.riderGroup.riders.at(1).theRoute.addBackCustomCoordinate(12, 3);
  com1.riderGroup.riders.at(1).theRoute.addBackCustomCoordinate(10, 3);
  
  com1.riderGroup.riders.at(0).theRoute.addBackCustomCoordinate(11, 12);
  com1.riderGroup.riders.at(0).theRoute.addBackCustomCoordinate(11, 10);
  com1.riderGroup.riders.at(0).theRoute.addBackCustomCoordinate(11, 8);
  com1.riderGroup.riders.at(0).theRoute.addBackCustomCoordinate(11, 6);

  // 2 运行公司运行逻辑

  int state = 0;
  while(state==0) {
	  // 2-1 运行派单逻辑
          while (!originSalesList.Saleslist.empty() &&
                    originSalesList.Saleslist.at(0).time == com1.worldTime) {
                    com1.receiveDistributeTheTask(originSalesList.Saleslist.at(0).no,
                                             originSalesList.Saleslist.at(0).time,
                                             originSalesList.Saleslist.at(0).restAddX,
                                             originSalesList.Saleslist.at(0).restAddY,
                                             originSalesList.Saleslist.at(0).cusAddX,
                                             originSalesList.Saleslist.at(0).cusAddY);
               originSalesList.Saleslist.pop_front();
          }
	  
		// 2-2 公司运行逻辑 （更新订单状态-输出-更新路线图-行走-time+=1）
		  
		  // 2-2-1 更新订单状态-输出文件-更新路线图
		  com1.UpdateCompany();
		  // 2-2-2 输出到屏幕
            // 2-2-2-1 重新加载屏幕数据
                  mapScreen.ReloadTheScreenData(com1);
            // 2-2-2-2 根据重新加载的屏幕数据进行打印活动对象
                  mapScreen.PrintChangableElem();
                  mapScreen.PrintChangableWords();
		    // 2-2-2-3 TODO::根据outputThisTime数据进行终止判断退出循环不运行擦除
				  // 状态 1 结束 : 所有骑手订单已完成，且输入总列表为空
				  // 状态 2 结束 : 破产并且在此刻被吊销执照
				  // 状态 3 结束 : 破产
				  // 状态 4 结束 : 吊销执照
                  if (com1.totalAsset < 0 && !com1.outputThisTime.thisTimeOut60TaskNO.empty()){
					  state = 2;
				  } else if(com1.totalAsset < 0) {
					  state = 3;
                  } else if (!com1.outputThisTime.thisTimeOut60TaskNO.empty()) {
					  state = 4;
				  } else if(
                      originSalesList.Saleslist.empty() &&
                      com1.riderGroup.judgeAllRidersTasklistEmpty()) {
                      state = 1;
                  } else {
					  state = 0;
				  }
            // 2-2-2-4 根据screen对象中所存的信息清理屏幕
                  Sleep(500);
                  mapScreen.ClearChangableElem();
            // 2-2-2-5 重置公司内thistime数据
                  com1.outputThisTime.resetMe();
		 // 2-2-3 行走-time+=1
				  com1.RunRidersAndWorldTime();
  }
  mapScreen.PrintChangableElem();
  mapScreen.PrintChangableWords();
  cout << state << endl;
  system("pause");
	return 0;
}


