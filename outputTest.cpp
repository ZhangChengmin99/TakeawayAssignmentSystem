#include <windows.h>
#include <iostream>
#include <string>

bool PrintRectangle(int x,int y);

using namespace std;
int main() {	
	//	// 1 ʹ���Զ������
 // SetConsoleTitle(L"TakeawayAssignmentSystem 1.0 by Group 22");
	//// 2 Sleep������������ʹ��
 // cout << "Hello World!\n";
 // Sleep(1000);
 // system("cls");
 // cout << "George Zhang\n";
  
	// 3 ���Դ�ӡһ��������
        PrintRectangle(3,4);
  system("pause");
  return 0;
}

bool PrintRectangle(int x, int y) {
  for (int i = 0; i < x; i++) {
    cout << "����������";
  }
  return true;
}