#include <windows.h>
#include <iostream>
#include <string>
#include "Company.h"

typedef struct tempLoc {
  int x;
  int y;
} tempLoc;

using namespace std;

void PrintBulidingCenterLine(int* count,deque<tempLoc>* tempLOC);
void PrintRoadCenterLine(int* count, deque<tempLoc>* tempLOC);


int main() {
  using namespace std;
  // 0 使用自定义标题
  SetConsoleTitle(L"TakeawayAssignmentSystem 1.0 by Group 22");
  // 1 生成假公司与测试数据
  Company com1 = Company(1, 15, 16);
  com1.buyRiders(2);
  com1.riderGroup.riders[1].coordinateOfSelf.changeCoordinate(14, 3);
  com1.riderGroup.riders[2].coordinateOfSelf.changeCoordinate(2, 15);
  // 2 创建保存骑手位置的队列保存位置
  std::deque<tempLoc>* tempLOC;
  tempLOC = new deque<tempLoc>;
  for (int i = 0; i < com1.riderGroup.riders.size(); i++) {
    tempLoc temp;
    temp.x = com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheXPosition();
    temp.y = com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheYPosition();
    tempLOC->push_back(temp);
  }
  // 打印装饰行
  cout << "\n ******************************************************************************************************************\n";
  cout << " *                                                                                                                *\n";
  cout << " *                                    TakeawayAssignmentSystem 1.0 by Group 22                                    *";
  cout << "\n *                                                                                                                *\n";
  cout << " ******************************************************************************************************************";
  cout << "\n *                                                                                                                *\n";
  // 打印标尺行
  cout << " *  ";
  cout << "  ";  // 预留竖列空格
  // 3-1 进入每一个格子横向8个英文字符,一共9个格子
  for (int i = 0; i < 10; i++) {
    if (i % 2) {
      cout << 0 << i << " ";
    }
    else {
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
  int count = 0;
  cout << "\n ";
  cout << "*    ";
  for (int i = 0; i < 8; i++) cout << "|￣￣￣|￣￣";
  cout << "|￣￣￣|";
  cout << "    *";
  // 打印建筑物中间行 重要：骑手位置判断逻辑

  PrintBulidingCenterLine(&count,tempLOC);
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
  PrintRoadCenterLine(&count,tempLOC);
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
    PrintBulidingCenterLine(&count, tempLOC);
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
    PrintRoadCenterLine(&count, tempLOC);
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
  PrintBulidingCenterLine(&count, tempLOC);
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
  // *********************************************
  cout << "\n "
          "********************************************************************"
          "**********************************************\n";
  cout << " *                                                                  "
          "                                              *\n";
  com1.printPartCompanyInfo();
  cout << " *                                                                  "
          "                                              *\n";
  cout << " "
          "********************************************************************"
          "**********************************************\n";
  //
  getchar();
  return 0;
}

void PrintBulidingCenterLine(int* count, deque<tempLoc> * tempLOC) {
  
  if (*count < 10) {
    cout << "\n" << " *  " << "0" <<*count;
  } else {
    cout << "\n" << " *  " << *count;
  }
  
  if ( tempLOC->size() == 0) {
    for (int i = 0; i < 8; i++) {
      cout << "|      | ";
      cout << "  ";
      putchar(' ');
    }
  } else {
    for (int i = 0; i < 8; i++) {
      cout << "|      | ";
      bool flag = false;
      for (int k = 0; k < tempLOC->size(); k++) {
        if (tempLOC->at(k).y == *count && tempLOC->at(k).x == 2 * i + 1) {
          flag = true;
          tempLOC->erase(tempLOC->begin() + k);
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
  *count += 1;
}

void PrintRoadCenterLine(int* count, deque<tempLoc>* tempLOC) {
  if (*count < 10) {
    cout << "\n"
         << " *  "
         << "0" << *count;
  } else {
    cout << "\n"
         << " *  " << *count;
  }
  if (tempLOC->size() == 0) {
    cout << "|           ";
    for (int i = 0; i < 7; i++) cout << "            ";
    cout << "       |";
  } else {
    // 打印道路中间行第一位置
    cout << "|  ";
    bool flag = false;
    for (int k = 0; k < tempLOC->size(); k++) {
      if (tempLOC->at(k).y == *count && tempLOC->at(k).x == 0) {
        flag = true;
        tempLOC->erase(tempLOC->begin() + k);
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
      for (int k = 0; k < tempLOC->size(); k++) {
        if (tempLOC->at(k).y == *count && tempLOC->at(k).x == 2 * (i + 1)) {
          flag = true;
          tempLOC->erase(tempLOC->begin() + k);
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
    for (int k = 0; k < tempLOC->size(); k++) {
      if (tempLOC->at(k).y == *count && tempLOC->at(k).x == 16) {
        flag = true;
        tempLOC->erase(tempLOC->begin() + k);
      }
    }
    if (flag) {
      cout << "█";
    } else {
      cout << "  ";
    }
    flag = false;
    cout << "  |    *";
    *count += 1;
  }
}