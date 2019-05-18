#include <windows.h>
#include <iostream>
#include <string>
using namespace std;
int main() {	
	// 1 使用自定义标题
  string title1 = "TakeawayAssignmentSystem 1.0 by Group 22";
  system(("title "+title1).c_str());
	// 2 Sleep和清屏函数的使用
  cout << "Hello World!\n";
  Sleep(1000);
  system("cls");
  cout << "George Zhang\n";
  system("pause");
  return 0;
}