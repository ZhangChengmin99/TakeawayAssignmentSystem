#include <windows.h>
#include <iostream>
#include <string>

bool PrintRectangle(int x,int y);

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
        PrintRectangle(3,4);
  system("pause");
  return 0;
}

bool PrintRectangle(int x, int y) {
  for (int i = 0; i < x; i++) {
    cout << "—————";
  }
  return true;
}