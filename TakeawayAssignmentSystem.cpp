#include <iostream>
#include "Company.h"
#include "Screen.h"

int main() {
  using namespace std;
  // 1 生成假公司与测试数据
  Company com1 = Company(1, 13, 16);
  com1.buyRiders(2);
  com1.riderGroup.riders[1].coordinateOfSelf.changeCoordinate(14, 3);
  com1.riderGroup.riders[2].coordinateOfSelf.changeCoordinate(2, 15);
  Screen mapScreen(com1);
  mapScreen.PrintTheAllMaps();
  com1.printPartCompanyInfo();
	return 0;
}


