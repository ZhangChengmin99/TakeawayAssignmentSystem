#include <windows.h>
#include <iostream>
#include <string>
using namespace std;
int main() {	
	// 1 ʹ���Զ������
  string title1 = "TakeawayAssignmentSystem 1.0 by Group 22";
  system(("title "+title1).c_str());
	// 2 Sleep������������ʹ��
  cout << "Hello World!\n";
  Sleep(1000);
  system("cls");
  cout << "George Zhang\n";
  system("pause");
  return 0;
}