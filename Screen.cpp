#include "Screen.h"
#include <windows.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>

Screen::Screen() {
	count = 0;
	tempLOC.clear();
    name = new char[100];
    receiveTaskNum = 0;
    finishedTaskNum = 0;
    outTimeTaskNum = 0;
    worldTime = 0;
    totalAsset = 0;
	basementY = 0;
}

Screen::Screen(Company com1,int baseY) {
  name = new char[100];
  strcpy_s(name, 100, com1.name);
  receiveTaskNum = com1.receiveTaskNum;
  finishedTaskNum = com1.finishedTaskNum;
  outTimeTaskNum = com1.outTimeTaskNum;
  worldTime = com1.worldTime;
  totalAsset = com1.totalAsset;
  tempdata = com1.outputThisTime;
  basementY = baseY;
  //
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
	for(auto i:tempLOC) {
		gotoxy(i);
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

void Screen::PrintChangableWords() {
  using namespace std;
  // 打印时间
  tempLoc temp = {21,64+basementY};
  gotoxy(temp);
  cout << setw(11) << setfill(' ') << worldTime;
  // 打印金钱
  temp = {21, 63+basementY};
  gotoxy(temp);
  cout << setw(10) << setfill(' ') << totalAsset;
  // 打印接收单数
  temp = {21, 65+basementY};
  gotoxy(temp);
  cout << setw(11) << setfill(' ') << receiveTaskNum;
  // 打印完成单数
  temp = {21, 66+basementY};
  gotoxy(temp);
  cout << setw(11) << setfill(' ') << finishedTaskNum;
  // 打印超时单数
  temp = {67, 62+basementY};
  gotoxy(temp);
  cout << outTimeTaskNum;
  // 6 打印完成订单编号
  // 6-1 清理订单编号位置
  temp = {53, 64+basementY};
  gotoxy(temp);
  cout << "                                                             ";
  // 6-2 打印新内容
  temp = {53, 64+basementY};
  gotoxy(temp);
  if(tempdata.thisTimeFinishedTaskNO.size()==0){
	  cout << "NO FINISHED TASKS IN THIS TIME!";
  } else {
	  for(auto i:tempdata.thisTimeFinishedTaskNO){
		cout << i << " ";
	  }
  }
  // 7 打印超时订单编号
  // 7-1 清理订单编号位置
  temp = {53, 66+basementY};
  gotoxy(temp);
  cout << "                                                             ";
  // 7-2 打印新内容
  temp = {53, 66+basementY};
  gotoxy(temp);
  if (tempdata.thisTimeFINEDTaskNO.size() == 0) {
    cout << "NO OUTTIME TASKS IN THIS TIME!";
  } else {
    for (auto i : tempdata.thisTimeFINEDTaskNO) {
      cout << i << " ";
    }
  }


  //
  temp = {0, 69 + basementY};
  gotoxy(temp);
}

void Screen::ClearchangableWords() {
	// 未用此方法
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
  using namespace std;
  cout << "\n "
          "********************************************************************"
          "**********************************************\n";
  cout << " *                                                                  "
          "                                              *\n";
  std::cout << " *   Company   Name: " << setw(11) << setfill(' ') << name
            << "                     OutTimeTaskN:                                                *\n";
  std::cout << " *   Company Assets:           $                     FinishedTaskNo(thisTime):                                    *\n";
  std::cout << " *   All World Time:                                                                                              *\n";
  std::cout << " *   Receive TasksN:                                 OutTimeTaskNo(thisTime):                                     *\n";
  std::cout << " *   Finished TaskN:                                                                                              *\n";
  cout << " *                                                            "
          "      "
          "                                              *\n";
  cout << " "
          "**************************************************************"
          "******"
          "**********************************************\n";
  
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

void Screen::ReloadTheScreenData(Company com1) {
  tempdata = com1.outputThisTime;
  receiveTaskNum = com1.receiveTaskNum;
  finishedTaskNum = com1.finishedTaskNum;
  outTimeTaskNum = com1.outTimeTaskNum;
  worldTime = com1.worldTime;
  totalAsset = com1.totalAsset;
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
