#include <iostream>
#include <windows.h>
#include "Company.h"
#include "Screen.h"

int main() {
  using namespace std;
  // 1 生成假公司与测试数据
  Company com1 = Company(1, 11, 14);
  com1.buyRiders(2);
  com1.riderGroup.riders[1].coordinateOfSelf.changeCoordinate(14, 3);
  com1.riderGroup.riders[2].coordinateOfSelf.changeCoordinate(2, 15);
  Screen mapScreen(com1);
  mapScreen.PrintTheBasicMap();
  com1.printPartCompanyInfo();
  //
  for(int i = 0;i<4;i++){
    mapScreen.PrintChangableElem();
    
    com1.riderGroup.riders[1].coordinateOfSelf.move(Coordinate::leftStraight);
    com1.riderGroup.riders[0].coordinateOfSelf.move(Coordinate::upStraight);
    com1.riderGroup.riders[2].coordinateOfSelf.move(Coordinate::rightStraight);
    Sleep(500);
    mapScreen.ClearChangableElem();
    mapScreen.ReloadTheTempLOC(com1);
    
  }
  mapScreen.PrintChangableElem();
    
  system("pause");
	return 0;
}


