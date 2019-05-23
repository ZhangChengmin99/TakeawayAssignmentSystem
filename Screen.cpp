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
    tempLoc temp;
    temp.x = com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheXPosition();
    temp.y = com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheYPosition();
    tempLOC.push_back(temp);
  }
}



void Screen::PrintTheAllMaps() {
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

  if (tempLOC.size() == 0) {
    for (int i = 0; i < 8; i++) {
      cout << "|      | ";
      cout << "  ";
      putchar(' ');
    }
  } else {
    for (int i = 0; i < 8; i++) {
      cout << "|      | ";
      bool flag = false;
      for (int k = 0; k < tempLOC.size(); k++) {
        if (tempLOC.at(k).y == count && tempLOC.at(k).x == 2 * i + 1) {
          flag = true;
          tempLOC.erase(tempLOC.begin() + k);
        }
      }
      if (flag) {
        cout << "█";
      } else {
        cout << "  ";
      }
      putchar(' ');
    }
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
  if (tempLOC.size() == 0) {
    cout << "|           ";
    for (int i = 0; i < 7; i++) cout << "            ";
    cout << "       |";
  } else {
    // 打印道路中间行第一位置
    cout << "|  ";
    bool flag = false;
    for (int k = 0; k < tempLOC.size(); k++) {
      if (tempLOC.at(k).y == count && tempLOC.at(k).x == 0) {
        flag = true;
        tempLOC.erase(tempLOC.begin() + k);
      }
    }
    if (flag) {
      cout << "█";
    } else {
      cout << "  ";
    }
    cout << "       ";
    // 打印道路中间行中间位置
    for (int i = 0; i < 7; i++) {
      flag = false;
      cout << "   ";
      for (int k = 0; k < tempLOC.size(); k++) {
        if (tempLOC.at(k).y == count && tempLOC.at(k).x == 2 * (i + 1)) {
          flag = true;
          tempLOC.erase(tempLOC.begin() + k);
        }
      }
      if (flag) {
        cout << "█";
      } else {
        cout << "  ";
      }
      cout << "       ";
    }
    // 打印道路中间行最后位置
    cout << "   ";
    flag = false;
    for (int k = 0; k < tempLOC.size(); k++) {
      if (tempLOC.at(k).y == count && tempLOC.at(k).x == 16) {
        flag = true;
        tempLOC.erase(tempLOC.begin() + k);
      }
    }
    if (flag) {
      cout << "█";
    } else {
      cout << "  ";
    }
    flag = false;
    cout << "  |    *";
    count += 1;
  }
}

void Screen::ReloadTheTempLOC(Company com1) {
	count = 0;
	tempLOC.clear();
  for (int i = 0; i < com1.riderGroup.riders.size(); i++) {
    tempLoc temp;
    temp.x = com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheXPosition();
    temp.y = com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheYPosition();
    tempLOC.push_back(temp);
  }
}

Screen::~Screen() {}
