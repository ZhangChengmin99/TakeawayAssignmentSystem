#include <windows.h>
#include <iostream>
#include <string>

bool PrintRectangle(int x);

using namespace std;
int main() {
  //	// 1 使用自定义标题
  // SetConsoleTitle(L"TakeawayAssignmentSystem 1.0 by Group 22");
  //// 2 Sleep和清屏函数的使用
  // cout << "Hello World!\n";
  // Sleep(1000);
  // system("cls");
  // cout << "George Zhang\n";

  // 3 尝试打印一个正方形
  //PrintRectangle(3);
  system("pause");
  return 0;
}

// Print the 

// 写着玩的函数（实际应当逐行扫描）
bool PrintRectangle(int x) {
  if (x < 1) return false;
  cout << "   ";
  cout << "■";
  cout << "\n";
  cout << "|";
  for (int i = 0; i < x; i++) {
    cout << "￣";
  }
  cout << "|";
  cout << "\n";
  cout << "|";
  for (int i = 0; i < 2*x; i++) {
    cout << " ";
  }
  cout << "|";
  cout << "■";
  cout << "\n";
  cout << "|";
  for (int i = 0; i < 2 * x; i++) {
    cout << " ";
  }
  cout << "|";
  cout << "\n";
  cout << " ";
  for (int i = 0; i < x; i++) {
    cout << "￣";
  }
  return true;
}