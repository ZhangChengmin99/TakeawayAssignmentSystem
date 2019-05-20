#include <windows.h>
#include <iostream>
#include <string>
#include "Company.h"

typedef struct tempLoc {
  int x;
  int y;
} tempLoc;

bool PrintRectangle(int x);
void PrintReferencedNumX();

using namespace std;

int main() {
  // 0 使用自定义标题
  SetConsoleTitle(L"TakeawayAssignmentSystem 1.0 by Group 22");
  // 1 生成假公司与测试数据
  Company com1 = Company(3, 8, 7);
  com1.riderGroup.riders[0].coordinateOfSelf.changeCoordinate(15, 0);
  com1.riderGroup.riders[1].coordinateOfSelf.changeCoordinate(1, 14);
  // 2 创建保存骑手位置的队列保存位置
  std::deque<tempLoc> tempLOC;
  for (int i = 0; i < com1.riderGroup.riders.size(); i++) {
    tempLoc temp;
    temp.x = com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheXPosition();
    temp.y = com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheYPosition();
    tempLOC.push_back(temp);
  }
  // 3 尝试打印第-1行
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
  cout << "   16   ";

  // ***************** 打印第0行 ******************
  // 4 尝试打印第0-0(0)行
  int count = 0;
  cout << "\n  ";
  for (int i = 0; i < 8; i++) cout << "|￣￣￣|￣￣";
  cout << "|￣￣￣|";
  // 5 尝试打印第0-1(1)行 重要：骑手位置判断逻辑
  cout << "\n0" << count;
  count += 1;
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
      for (int k = 0; k < tempLOC.size();k++) {
        if (tempLOC.at(k).y == 0 && tempLOC.at(k).x == 2 * i + 1) {
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
  // *********************************************


  // ***************** 打印第1行 ******************
  cout << "|      |";
  // 6 尝试打印第0-2(2)行
  cout << "\n  ";
  for (int i = 0; i < 8; i++) cout << "|      |    ";
  cout << "|      |";
  // 7 尝试打印第1-0(3)行
  cout << "\n  ";
  cout << "|￣￣￣     ";
  for (int i = 0; i < 7; i++) cout << " ￣￣￣     ";
  cout << " ￣￣￣|";
  // 7 尝试打印第1-1(4)行 重要：骑手位置判断逻辑
  cout << "\n0" << count;
  count += 1;
  cout << "|  █       ";
  for (int i = 0; i < 7; i++) cout << "   █       ";
  cout << "   █  |";
  // 7 尝试打印第1-2(5)行
  cout << "\n  ";
  cout << "|           ";
  for (int i = 0; i < 7; i++) cout << "            ";
  cout << "       |";
 

  // ***************** 打印循环 ******************
  while (count < 16) {
    cout << "\n  ";
    for (int i = 0; i < 8; i++) cout << "|￣￣￣|    ";
    cout << "|￣￣￣|";
    // 5 尝试打印第0-1(1)行
    if (count < 10) {
      cout << "\n0" << count;
    } else {
      cout << "\n" << count;
    }
    count += 1;
    for (int i = 0; i < 8; i++) cout << "|      |    ";
    cout << "|      |";
    // 6 尝试打印第0-2(2)行
    cout << "\n  ";
    for (int i = 0; i < 8; i++) cout << "|      |    ";
    cout << "|      |";
    // 7 尝试打印第1-0(3)行
    cout << "\n  ";
    cout << "|￣￣￣     ";
    for (int i = 0; i < 7; i++) cout << " ￣￣￣     ";
    cout << " ￣￣￣|";
    // 7 尝试打印第1-1(4)行
    if (count < 10) {
      cout << "\n0" << count;
    } else {
      cout << "\n" << count;
    }
    count += 1;
    cout << "|           ";
    for (int i = 0; i < 7; i++) cout << "            ";
    cout << "       |";
    // 7 尝试打印第1-2(5)行
    cout << "\n  ";
    cout << "|           ";
    for (int i = 0; i < 7; i++) cout << "            ";
    cout << "       |";
  }
  // *********************************************


  // ***************** 打印第16行 ******************
  cout << "\n  ";
  for (int i = 0; i < 8; i++) cout << "|￣￣￣|    ";
  cout << "|￣￣￣|";
  // 5 尝试打印第0-1(1)行
  if (count < 10) {
    cout << "\n0" << count;
  } else {
    cout << "\n" << count;
  }
  count += 1;
  for (int i = 0; i < 8; i++) cout << "|      |    ";
  cout << "|      |";
  // 6 尝试打印第0-2(2)行
  cout << "\n  ";
  for (int i = 0; i < 8; i++) cout << "|      |    ";
  cout << "|      |";
  cout << "\n  ";
  for (int i = 0; i < 8; i++) cout << " ￣￣￣ ￣￣";
  cout << " ￣￣￣ ";
  // *********************************************

  //
  getchar();
  return 0;
}

// Print the

// 写着玩的函数（实际应当逐行扫描）
bool PrintRectangle(int x) {
  if (x < 1) return false;
  cout << "";
  cout << "  ■";
  cout << "\n";
  cout << "|";
  for (int i = 0; i < x; i++) {
    cout << "￣";
  }
  cout << "|■";
  cout << "\n ";
  for (int i = 0; i < x; i++) {
    cout << "￣";
  }
  return true;
}

// 打印参考横坐标行
void PrintReferencedNumX() {
  // 预留参考纵坐标
  cout << "  ";
  for (int i = 0; i < 17; i++) {
    cout << "   ";
    if (i < 10) {
      cout << "0" << i;
    } else {
      cout << i;
    }
    cout << "    ";
  }
  putchar('\n');
}