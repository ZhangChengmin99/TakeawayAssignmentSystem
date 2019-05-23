#include "Screen.h"
#include <windows.h>
#include <iostream>
#include <string>

Screen::Screen() {
	count = 0;
	tempLOC.clear();
}

Screen::Screen(Company com1) {
  count = 0;
  tempLOC.clear();
  for (int i = 0; i < com1.riderGroup.riders.size(); i++) {
    
    tempLOC.push_back(TransLocationToScreenXY(
        com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheXPosition(),
        com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheYPosition()));
  }
}



void Screen::PrintChangableElem() {
	using namespace std;
	for(int i = 0; i<tempLOC.size(); i++) {
		gotoxy(tempLOC.at(i));
		cout << "█";
	}
        tempLoc temp = {0, 69 + basementY};
        gotoxy(temp);
}

void Screen::ClearChangableElem() {
  using namespace std;
  for (int i = 0; i < tempLOC.size(); i++) {
    gotoxy(tempLOC.at(i));
    cout << "  ";
  }
  tempLoc temp = {0, 69 + basementY};
  gotoxy(temp);
}



void Screen::PrintTheBasicMap() {
	using namespace std;
  SetConsoleTitle(L"TakeawayAssignmentSystem 1.0 by Group 22");
  // 打印装饰行
  std::cout << "\n "
               "***************************************************************"
               "***************************************************\n";
  cout << " *                                                                  "
          "                                              *\n";
  cout << " *                                    TakeawayAssignmentSystem 1.0 "
          "by Group 22                                    *";
  cout << "\n *                                                                "
          "                                                *\n";
  cout << " *******************************************************************"
          "***********************************************";
  cout << "\n *                                                                "
          "                                                *\n";
  // 打印标尺行
  cout << " *  ";
  cout << "  ";  // 预留竖列空格
  // 3-1 进入每一个格子横向8个英文字符,一共9个格子
  for (int i = 0; i < 10; i++) {
    if (i % 2) {
      cout << 0 << i << " ";
    } else {
      cout << "   " << 0 << i << "    ";
    }
  }
  for (int i = 10; i < 16; i++) {
    if (i % 2) {
      cout << i << " ";
    } else {
      cout << "   " << i << "    ";
    }
  }
  cout << "   16       *";

  // 打印建筑物屋顶
  cout << "\n ";
  cout << "*    ";
  for (int i = 0; i < 8; i++) cout << "|￣￣￣|￣￣";
  cout << "|￣￣￣|";
  cout << "    *";
  // 打印建筑物中间行 重要：骑手位置判断逻辑

  PrintBulidingCenterLine();
  // 打印建筑物最后一行没有底
  cout << "\n ";
  cout << "*    ";
  for (int i = 0; i < 8; i++) cout << "|      |    ";
  cout << "|      |    *";
  // 打印建筑物底和道路第一行
  cout << "\n ";
  cout << "*    ";
  cout << "|￣￣￣     ";
  for (int i = 0; i < 7; i++) cout << " ￣￣￣     ";
  cout << " ￣￣￣|    *";
  // 打印道路中间行 重要：骑手位置判断逻辑
  PrintRoadCenterLine();
  // 打印道路最后一行
  cout << "\n ";
  cout << "*    ";
  cout << "|           ";
  for (int i = 0; i < 7; i++) cout << "            ";
  cout << "       |    *";

  // ***************** 打印循环 ******************
  while (count < 16) {
    // 打印建筑物屋顶
    cout << "\n ";
    cout << "*    ";
    for (int i = 0; i < 8; i++) cout << "|￣￣￣|    ";
    cout << "|￣￣￣|    *";
    // 打印建筑物中间行
    PrintBulidingCenterLine();
    // 打印建筑物最后行
    cout << "\n ";
    cout << "*    ";
    for (int i = 0; i < 8; i++) cout << "|      |    ";
    cout << "|      |    *";
    // 打印建筑物底和道路第一行
    cout << "\n ";
    cout << "*    ";
    cout << "|￣￣￣     ";
    for (int i = 0; i < 7; i++) cout << " ￣￣￣     ";
    cout << " ￣￣￣|    *";
    // 打印道路中间行
    PrintRoadCenterLine();
    // 打印道路最后一行
    cout << "\n ";
    cout << "*    ";
    cout << "|           ";
    for (int i = 0; i < 7; i++) cout << "            ";
    cout << "       |    *";
  }
  // *********************************************

  // ***************** 打印第16行 ******************
  // 打印建筑物顶
  cout << "\n ";
  cout << "*    ";
  for (int i = 0; i < 8; i++) cout << "|￣￣￣|    ";
  cout << "|￣￣￣|    *";
  // 打印建筑物中间行
  PrintBulidingCenterLine();
  // 打印建筑物最后一行
  cout << "\n ";
  cout << "*    ";
  for (int i = 0; i < 8; i++) cout << "|      |    ";
  cout << "|      |    *";
  cout << "\n ";
  // 打印建筑物的底
  cout << "*    ";
  for (int i = 0; i < 8; i++) cout << " ￣￣￣ ￣￣";
  cout << " ￣￣￣     *";
  
}

void Screen::PrintBulidingCenterLine() {
	using namespace std;
  if (count < 10) {
    cout << "\n"
         << " *  "
         << "0" << count;
  } else {
    cout << "\n"
         << " *  " << count;
  }

  for (int i = 0; i < 8; i++) {
      cout << "|      | ";
      cout << "  ";
      putchar(' ');
    }
  cout << "|      |    *";
  count += 1;
}

void Screen::PrintRoadCenterLine() {
	using namespace std;
  if (count < 10) {
    cout << "\n"
         << " *  "
         << "0" << count;
  } else {
    cout << "\n"
         << " *  " << count;
  }
  
    cout << "|           ";
    for (int i = 0; i < 7; i++) cout << "            ";
    cout << "       |    *";
	count += 1;
}

void Screen::gotoxy(tempLoc tempLOC) {
  COORD pos = {tempLOC.x,tempLOC.y};
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取标准输出设备句柄
  SetConsoleCursorPosition(hOut, pos);  //两个参数分别是指定哪个窗体，具体位置
}

tempLoc Screen::TransLocationToScreenXY(int x, int y) { 
	y = 9 + basementY + 3*y;
	// 如果x是偶数
	if(x%2==0){
		x = 9 + (x/2) * 12;
	} else {
		x = 15 + ( (x-1) / 2 ) * 12;
	}
	tempLoc tempLOC = {x,y};
	return tempLOC; 
}

void Screen::ReloadTheTempLOC(Company com1) {
	count = 0;
	tempLOC.clear();
  for (int i = 0; i < com1.riderGroup.riders.size(); i++) {
    tempLOC.push_back(TransLocationToScreenXY(
              com1.riderGroup.riders.at(i)
                  .coordinateOfSelf.returnTheXPosition(),
              com1.riderGroup.riders.at(i)
                  .coordinateOfSelf.returnTheYPosition()));
  }
}

Screen::~Screen() {}
